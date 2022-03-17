#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Not enough arguments.\n");
		exit(1);
	}
	// VARIABLES
	// for parent
	int status;
	char number[20];
	// create PIPE
	int fd[2];

	// create pipe
	if (pipe(fd) == -1) {
		fprintf(stderr, "Pipe failed");
		return -1;
	}
	pid_t pid = getpid();
	pid_t cPid = fork();

	// CHILD 1
	if (cPid < 0) {
		fprintf(stderr, "Fork Failed\n");
		exit(2);
	}
	// child calls the program fibb
	else if (cPid == 0) {
		// close up read in
		close(fd[0]);
		// pipe refernce storage
		char pipe_ref[16];
		// use sprintf() to get file descriptor of write end
		sprintf(pipe_ref, "%d", fd[1]);
		// pass 
		execlp("./CharacterReader", "./CharacterReader", argv[1], pipe_ref, NULL);
		// close write side
		close(fd[1]);
	}
	// PARENT prints the return value from child using WEXITSTATUS
	else {
		// close parents output side of pipe
		close(fd[1]);
		wait(&status);

		int info_recived = read(fd[0], number, sizeof(number));
		number[info_recived] = '\0';
		close(fd[0]);
		printf("Starter[%d]: Contents read from the read end pipe: %s\n", pid, number);
		close(fd[0]);
	}

	// name of memory sequence
	char SHM_F[] = "SHM_Fibb";
	char SHM_P[] = "SHM_Prime";
	char SHM_T[] = "SHM_Total";

	// create memory segment
	int SHM_FDF = shm_open(SHM_F, O_CREAT | O_RDWR, 0666);
	int SHM_FDP = shm_open(SHM_P, O_CREAT | O_RDWR, 0666);
	int SHM_FDT = shm_open(SHM_T, O_CREAT | O_RDWR, 0666);

	// set the size of mem segment
	int SIZE = 32;
	ftruncate(SHM_FDF, SIZE);
	ftruncate(SHM_FDP, SIZE);
	ftruncate(SHM_FDT, SIZE);

	// map newly created mem segments
	void* SHM_Fptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, SHM_FDF, 0);
	void* SHM_Pptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, SHM_FDP, 0);
	void* SHM_Tptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, SHM_FDT, 0);

	printf("Starter[%d]: Created shared memory \"%s\" with FD: %d\n", pid, SHM_F, SHM_FDF);
	printf("Starter[%d]: Created shared memory \"%s\" with FD: %d\n", pid, SHM_P, SHM_FDP);
	printf("Starter[%d]: Created shared memory \"%s\" with FD: %d\n", pid, SHM_T, SHM_FDT);

	// 2d array holding execution file and memory segments
	char* x[2][3] = {
		{"./Total","./Prime","./Fibb"},
		{SHM_Tptr, SHM_Pptr, SHM_Fptr}
	};
	// used to create children and parents
	pid_t cPids[3];
	for (int i = 0; i < 3; i++) {
		if(cPids[i] = fork() == 0) {
			execlp(x[0][i], x[0][i], x[1][i], number, NULL);
		}
	}
	for (int j = 0; j < 3; j++) {
		waitpid(cPids[j], &status, WCONTINUED);
	}

	printf("Starter[%d]: Fibb last number: %s\n", pid, SHM_Fptr);
	printf("Starter[%d]: Prime last number: %s\n", pid, SHM_Pptr);
	printf("Starter[%d]: Total last number: %s\n", pid, SHM_Tptr);

	return 0;
}