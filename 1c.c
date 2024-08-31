/*
============================================================================
Name : 1c.c
Author : Gaurav Verma
Description : Write a C, Ansi-style program to perform Record locking.
                       c. FIFO (mkfifo Library Function or mknod system call)
Date: 16th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int o = mkfifo(argv[1], 0700);
    if (o == 0) {
        printf("Success - FIFO file created\n");
    } else {
        perror("Error");
        return 1;
    }

    return 0;
}
