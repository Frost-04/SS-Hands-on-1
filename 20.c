/*
============================================================================
Name : 20.c
Author : Gaurav Verma
Description :  Find out the priority of your running program. Modify the priority with nice command
Date: 23rd Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>

int main() {
    int pid;
    printf("Enter process ID: ");
    scanf("%d", &pid);

    int nice_value = getpriority(PRIO_PROCESS, pid);
    int priority = 20 + nice_value;

    printf("The nice value is: %d\n", nice_value);
    printf("The priority is: %d\n", priority);

    return 0;
}
