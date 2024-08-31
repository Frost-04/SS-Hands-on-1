/*
============================================================================
Name : 23.c
Author : Gaurav Verma
Description :  Write a program to create a Zombie state of the running program.

Date: 25th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    int fd;
    fd = fork();
    if (fd > 0) {
        // parent process will take time so that child will complete
        printf("Parent process is running. Parent-PID: %d\n", getpid());
        sleep(60);
    } else if (fd == 0) {
        // child process will complete before parent and become zombie
        printf("Written by child process. Child-PID: %d\n", getpid());
        return 0;
    }
    return 0;
}