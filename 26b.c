/*
============================================================================
Name : 26b.c
Author : Gaurav Verma
Description : Write a program to execute an executable program.
              b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 27th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    char *path=argv[1];
    execv(path, &argv[1]);
    return 0;
}