/*
============================================================================
Name : 27c.c
Author : Gaurav Verma
Description : Write a program to execute ls -Rl by the following system calls
                 c. execle
Date: 28th Aug, 2024.
============================================================================
*/
#include <unistd.h>

int main(int argc,char *argv[],char *env[]) {
    execle("/bin/ls", "ls", "-Rl", NULL, env);
    return 0;
}