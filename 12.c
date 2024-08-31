/*
============================================================================
Name : 12.c
Author : Gaurav Verma
Description : Write a program to find out the opening mode of a file. Use fcntl.

Date: 20th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argv, char *argc[]) {
    int fd = open(argc[1], O_RDONLY);
    if (fd == -1) {
        perror("Error!");
        close(fd);
        return 0;
    }
    int fmode = fcntl(fd, F_GETFL);
    int accessMode = fmode & O_ACCMODE;
    if (accessMode == O_RDONLY) {
        printf("The file is opened in read-only mode.\n");
    } else if (accessMode == O_WRONLY) {
        printf("The file is opened in write-only mode.\n");
    } else if (accessMode == O_RDWR) {
        printf("The file is opened in read-write mode.\n");
    }
    return 0;
}