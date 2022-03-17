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

int main(int argc,char *argv[]){
    int end = atoi(argv[2]);
    int prev = 0, current = 1, next;
    int SIZE = 32;

    // Step 5
    // print Pid and it should match Pid from fork()
    printf("Fibb[%d] : Number of terms in fibonacii series is %d\n", getpid(), end);
    printf("Fibb[%d] : The first %d numbers of the fibonacci sequence are:\n", getpid(), end);
    // step 6
    // fibonacii
    for(int i = 1; i <= end; ++i){
        if(i == end){
            printf("%d,\n",prev);
            break;
        }
        printf("%d, ", prev);
        next = prev + current;
        prev = current;
        current = next;
    }
    // return nth fibonacii number ( n being value of string)
    char SHM_F[] = "SHM_Fibb";
    int SHM_FDF = shm_open(SHM_F, O_CREAT | O_RDWR, 0666);
    void* SHM_Fptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, SHM_FDF, 0);
    sprintf(SHM_Fptr, "%d", prev);
    unlink(SHM_F);
    return prev;
}