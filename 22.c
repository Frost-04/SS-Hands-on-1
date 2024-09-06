/*
============================================================================
Name : 22.c
Author : Gaurav Verma
Description : Write a program, open a file, call fork, and then write to the
file by both the child as well as the parent processes. Check output of the
file. Date: 24th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    fork();
    int fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0700);
    if (fd == -1) {
        perror("Error!");
        close(fd);
        return 0;
    }
    char buffer[30];
    snprintf(buffer, sizeof(buffer), "Process %d wrote this.\n", getpid());
    write(fd, buffer, sizeof(buffer));
    close(fd);

    return 0;
}

// Output Sample:-

// Process 58 wrote this.
// Process 59 worte this.
