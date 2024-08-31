/*
============================================================================
Name : 16.c
Author : Gaurav Verma
Description : Write a program to perform mandatory locking.
                a. Implement write lock
                b. Implement read lock
Date: 21st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argv, char *argc[])
{
    int fd = open(argc[1], O_WRONLY);
    if (fd == -1) {
        perror("Error!");
        close(fd);
        return 0;
    }
    struct flock lock = {F_WRLCK,0,0,0,0};

    fcntl(fd, F_SETLKW, &lock);
    printf("File locked.\n Press enter to unlock\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    return 0; 
}