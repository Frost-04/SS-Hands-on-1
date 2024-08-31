/*
============================================================================
Name : 6.c
Author : Gaurav Verma
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 19th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>  //for read write sys calls
int main() {
    char buffer[1024];
    int size = 0;
    size = read(0, buffer, 1024);
    write(1, buffer, size);

    return 0;
}

