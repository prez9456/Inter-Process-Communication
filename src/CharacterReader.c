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

# define MAXCHAR 100

void main(int argc,char *argv[]){
    // variables
    int sum = 0;
    // str is the input being passed to functions
    char str[MAXCHAR];   
    char result[MAXCHAR];
    // atoi copies pipe_ref
    int COPYfd = atoi(argv[2]);

    // read contents line by line & counter
    FILE *in = fopen(argv[1], "r");
    if(in == NULL){
        fprintf(stderr, "File failed to open.\n");
        exit(1);
    }

    while(fgets(str, sizeof(str),in)){
        sum += atoi(str);
    }
    fclose(in);
    // sprintf the sum and pass that to write
    sprintf(result, "%d", sum);
    //write contents into pipe
    write(COPYfd, result, strlen(result)+1);
    // close pipe
    close(COPYfd);
}