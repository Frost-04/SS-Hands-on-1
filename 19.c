/*
============================================================================
Name : 19.c
Author : Gaurav Verma
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter. 
Date: 23rd Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc": "=A"(dst));
    return dst;
}

void main()
{
    long long int start, end,pid;

    start = rdtsc();
    
    pid=getpid();

    end = rdtsc();

    printf("Process ID is : %llu\n", pid);
    printf("Difference is : %llu Clocks\n", end - start);
}

//Output Sample:-

/*
Process ID is : 32
Difference is : 7094 Clocks
*/