/*
============================================================================
Name : 1b.c
Author : Gaurav Verma
Description : Write a C, Ansi-style program to perform Record locking.
                        b. hard link (link system call)
Date: 16th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int o = link(argv[1], argv[2]);
    if (o == 0) {
        printf("Success - Hardlink created!\n");
    } else {
        perror("Error");
        return 1;
    }

    return 0;
}
