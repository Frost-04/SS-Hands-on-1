/*
============================================================================
Name : 4.c
Author : Gaurav Verma
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also
Date: 17th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void main() {
    int fd;

    // opens a file with R-W mode also uses EXCL flag.
    fd = open("newfileexample.txt", O_RDWR | O_CREAT | O_EXCL, 0644);

    if (fd == -1) {
        // Error checking
        perror("Error!\n");
    }

    else {
        printf("File opened/created successfully.\n");

        close(fd);
    }
}

//output sample:-

//File opened/created successfully.
