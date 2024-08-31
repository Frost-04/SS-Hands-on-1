/*
============================================================================
Name : 27a.c
Author : Gaurav Verma
Description : Write a program to execute ls -Rl by the following system calls
                 a. execl
Date: 27th Aug, 2024.
============================================================================
*/
#include <unistd.h>

int main() {
    execl("/bin/ls", "ls", "-Rl", NULL);
    return 0;
}