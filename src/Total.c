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

int main(int argc, char *argv[]){
    // variables
    int end = atoi(argv[2]);
    int SIZE = 32;
    //int COPYfd = atoi(argv[1]);

    // step 6
    // total sum
    int sum = 0;
    for(int i = 0; i <= end; i++){
        sum += i;
    }
    // Step 5
    // print Pid and it should match Pid from fork()
    // return the sum of first n number (n being value of string)
    printf("Total[%d] : Sum = %d\n", getpid(), sum);
    char SHM_T[] = "SHM_Total";
    int SHM_FDT = shm_open(SHM_T, O_CREAT | O_RDWR, 0666);
    void* SHM_Tptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, SHM_FDT, 0);
    sprintf(SHM_Tptr, "%d", sum);
    unlink(SHM_T);
    return sum;
}