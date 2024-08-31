/*
============================================================================
Name : 1a.c
Author : Gaurav Verma
Description : Write a C, Ansi-style program to perform Record locking.
                       a. Implement write lock
Date: 16th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int o = symlink(argv[1], argv[2]);
    if (o == 0) {
        printf("Success - Softlink created!\n");
    } else {
        perror("Error");
        return 1;
    }

    return 0;
}
