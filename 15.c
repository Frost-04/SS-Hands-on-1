/*
============================================================================
Name : 15.c
Author : Gaurav Verma
Description : Write a program to display the environmental variable of the user (use environ).
Date: 21st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
extern char **environ;
void main()
{
    while (*environ) {
        printf("%s\n", *environ);
        environ++;
    }
}