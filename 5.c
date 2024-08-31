/*
============================================================================
Name : 5.c
Author : Gaurav Verma
Description :   Write a program to create five new files with infinite loop. Execute the program in the background
                and check the file descriptor table at /proc/pid/fd.
Date: 19th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main() {
    int fd[5], i;
    char filename[20];
    for (i = 0; i < 5; i++) {
        snprintf(filename, sizeof(filename), "5.c_file%d.txt", i + 1);
        fd[i] = open(filename, O_CREAT | O_RDWR, 0644);

        if (fd[i] == -1) {
            perror("Failed");
            exit(1);
        }
    }
    while (1) {
        sleep(1);  //  To keep the resource usage minimal.
    }
}

