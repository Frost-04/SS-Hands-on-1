/*
============================================================================
Name : 24.c
Author : Gaurav Verma
Description : Write a program to create an orphan process.

Date: 25th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int fd = fork();

    if (fd > 0) {
        // parent process will complete quickly.
        printf("Parent process exiting. PID: %d\n", getpid());
    } else if (fd == 0) {
        // child process will sleep unitl parent completes.
        sleep(10);
        printf("Child process running as an orphan. PID: %d, Parent PID: %d\n", getpid(), getppid());
    }

    return 0;
}


//Output Sample:-

/*
Parent process exiting. PID: 71
Child process running as an orphan. PID: 72, Parent PID: 12
*/