/*
============================================================================
Name : 27e.c
Author : Gaurav Verma
Description : Write a program to execute ls -Rl by the following system calls
                 e. execvp
Date: 29th Aug, 2024.
============================================================================
*/
#include <unistd.h>

int main() {
    char *param[] = {"ls", "-Rl", NULL};
    execvp("ls", param);
    return 0;
}