/*
============================================================================
Name : 28.c
Author : Gaurav Verma
Description : Write a program to get maximum and minimum real time priority.
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sched.h>

int main() {
    int min, max;

    min = sched_get_priority_min(SCHED_FIFO);
    max = sched_get_priority_max(SCHED_FIFO);
    
    printf("Priorities for FIFO: Min= %d, Max= %d\n", min, max);

    max = sched_get_priority_max(SCHED_RR);
    min = sched_get_priority_min(SCHED_RR);
    printf("Priorities for RR: Min= %d, Max= %d\n", min, max);

    return 0;
}
