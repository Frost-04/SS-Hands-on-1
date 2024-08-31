/*
============================================================================
Name : 21.c
Author : Gaurav Verma
Description :  Write a program, call fork and print the parent and child process id
Date: 23rd Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    
    int parent=getpid();

    printf("Parent PID: %d\n", parent);

    int process_id = fork();

    if (process_id) {
        printf("Child PID: %d\n", process_id);
    }

    return 0;
}

//Output Sample:-

/*
Parent PID: 53
Child PID: 54
*/