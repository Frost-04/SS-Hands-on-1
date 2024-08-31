/*
============================================================================
Name : 17a.c
Author : Gaurav Verma
Description : Write a program to simulate online ticket reservation. Implement write lock
              Write a program to open a file, store a ticket number and exit
Date: 21st Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("ticket.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int ticket_number = 1000;
    char buffer[20];
    int len = snprintf(buffer, sizeof(buffer), "%d\n", ticket_number);

    write(fd, buffer, len);
    printf("Wrote to the file!\n");

    close(fd);
    return 0;
}
