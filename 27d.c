/*
============================================================================
Name : 27d.c
Author : Gaurav Verma
Description : Write a program to execute ls -Rl by the following system calls
                 d. execv
Date: 28th Aug, 2024.
============================================================================
*/
#include <unistd.h>

int main() {
    char *param[] = {"/bin/ls", "-Rl", NULL};
    execv("/bin/ls", param);
    return 0;
}