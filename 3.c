/*
============================================================================
Name : 3.c
Author : Gaurav Verma
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 16th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = creat("creatfile3.txt", 0600);

    if (fd == -1) {
        perror("Error creating the file");
        return 1;
    }

    // Print the file descriptor value
    printf("File descriptor value: %d\n", fd);
    close(fd);

    return 0;
}
