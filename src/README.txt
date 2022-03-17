README
======

A. This package includes the following files.

|-- Starter.c
|-- Fibb.c
|-- Prime.c
|-- Total.c
|-- CharacterReader.c
|-- Makefile
|-- README.txt [This file]


B. Use your designed makefile 
To compile the code and build the executable using the command 

systemprompt>  make

To remove the  executable files use

systemprompt>  make clean

To run the program use (assuming data.txt) 

systemprompt> ./Starter data.txt

which will run the program and generate the outputs.


C. Answer the following questions (Select/type the right answer).
    1. Name the function that is used to create a pipe. Which ends denotes the read and the write
       ends of a pipe? (2 points)
	- pipe() is used to create a pipe with a int array passed in.
	  fd[0] is the read side and fd[1] is the write in side

    2. Name the function used to map files or devices in to memory? (1 point)
	- mmap() is used to map files

    3. Name the function used to open a shared memory object? What does it return? (2 points)
	- shm_open() is used to open a shared memory object. it returns 
	  a file descriptor for the shared memory object
 

D. Example Outputs
maggot:~/cs370/hw3$ ./Starter data.txt
Starter[816232]: Contents read from the read end pipe: 15
Starter[816232]: Created shared memory "SHM_Fibb" with FD: 3
Starter[816232]: Created shared memory "SHM_Prime" with FD: 4
Starter[816232]: Created shared memory "SHM_Total" with FD: 5
Total[816234] : Sum = 120
Prime[816235] : First 15 prime numbers are:
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
Fibb[816236] : Number of terms in fibonacii series is 15
Fibb[816236] : The first 15 numbers of the fibonacci sequence are:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377,
Starter[816232]: Fibb last number: 377
Starter[816232]: Prime last number: 47
Starter[816232]: Total last number: 120
maggot:~/cs370/hw3$

maggot:~/cs370/hw3$ ./Starter data.txt
Starter[816604]: Contents read from the read end pipe: 22
Starter[816604]: Created shared memory "SHM_Fibb" with FD: 3
Starter[816604]: Created shared memory "SHM_Prime" with FD: 4
Starter[816604]: Created shared memory "SHM_Total" with FD: 5
Fibb[816608] : Number of terms in fibonacii series is 22
Fibb[816608] : The first 22 numbers of the fibonacci sequence are:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946,
Total[816606] : Sum = 253
Prime[816607] : First 22 prime numbers are:
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
Starter[816604]: Fibb last number: 10946
Starter[816604]: Prime last number: 79
Starter[816604]: Total last number: 253
maggot:~/cs370/hw3$

