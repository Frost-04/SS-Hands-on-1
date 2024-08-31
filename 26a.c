/*
============================================================================
Name : 26a.c
Author : Gaurav Verma
Description : Write a program to execute an executable program.
              a. use some executable program
Date: 27th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    execv(argv[1], &argv[1]);
    return 0;
}