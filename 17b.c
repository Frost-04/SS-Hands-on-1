/*
============================================================================
Name : 17b.c
Author : Gaurav Verma
Description : Write a separate program, to open the file, implement write lock,
              read the ticket number, increment the number and print
              the new ticket number then close the file.

Date: 23rd Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd = open("ticket.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    struct flock lock = {F_WRLCK, SEEK_SET, 0, 0, 0};
    fcntl(fd, F_SETLKW, &lock);

    printf("Locked!\n");

    char buf[10];

    int n = read(fd, &buf, 10);

    int buf_int = atoi(buf);
    buf_int++;
    sprintf(buf, "%d", buf_int);

    lseek(fd, 0, SEEK_SET);
    write(fd, &buf, strlen(buf));
    printf("%d\t \n", buf_int);
    printf("Press enter to unlock!");

    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);

    printf("Unlocked!\n");
    return 0;
}