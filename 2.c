/*
============================================================================
Name : 2.c
Author : Gaurav Verma
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
                identify all the process related information in the corresponding proc directory. 
Date: 16th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        sleep(1);
    }
    return 0;
}
