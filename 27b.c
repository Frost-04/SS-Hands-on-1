/*
============================================================================
Name : 27bs.c
Author : Gaurav Verma
Description : Write a program to execute ls -Rl by the following system calls
                 b. execlp
Date: 28th Aug, 2024.
============================================================================
*/
#include <unistd.h>

int main() {
    execlp("ls", "ls", "-Rl", NULL);
    return 0;
}