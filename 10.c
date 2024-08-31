/*
============================================================================
Name : 10.c
Author : Gaurav Verma
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
              bytes (use lseek) and write again 10 bytes.
                a. check the return value of lseek
                b. open the file with od and check the empty spaces in between the data. 
Date: 20th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argv, char *argc[]) {
    int fd = open(argc[1], O_RDWR | O_CREAT, 0700);
    char s[10] = "ABCDEFGHIJ";
    if (fd == -1) {
        perror("Error!");
        close(fd);
        return 0;
    }

    write(fd, s, 10);
    int seeked = lseek(fd, 10, SEEK_CUR);
    printf("%d\n", seeked);
    write(fd, s, 10);
    seeked = lseek(fd, 0, SEEK_CUR);
    printf("%d\n", seeked);
    return 0;
}
