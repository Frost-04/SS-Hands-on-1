/*
============================================================================
Name : 29.c
Author : Gaurav Verma
Description :  Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
               SCHED_RR).
Date: 29th Aug, 2024.
============================================================================
*/
#include <sched.h>
#include <stdio.h>
#include <unistd.h>

void print_policy(int policy) {
    if (policy == SCHED_FIFO) {
        printf("Current scheduling policy: SCHED_FIFO\n");
    } else if (policy == SCHED_OTHER) {
        printf("Current scheduling policy: SCHED_OTHER\n");
    } else if (policy == SCHED_RR) {
        printf("Current scheduling policy: SCHED_RR\n");
    } else {
        printf("Unknown scheduling policy\n");
    }
}

void set_policy(int pid, int choice) {
    struct sched_param param;

    if (choice == 1)
        param.sched_priority = sched_get_priority_max(SCHED_FIFO);

    else if (choice == 2)
        param.sched_priority = sched_get_priority_max(SCHED_RR);

    else if (choice == 3)
        param.sched_priority = 0;

    else
        printf("Invalid choice\n");
}

int main() {
    int pid = getpid();
    int current_policy = sched_getscheduler(pid);

    if (current_policy == -1) {
        perror("Policy Error");
        return 1;
    }

    print_policy(current_policy);

    printf("Select new Policy:\n1: SCHED_FIFO\n2: SCHED_RR\n3: SCHED_OTHER\n");
    int choice;
    scanf("%d", &choice);

    set_policy(pid, choice);

    int new_policy = sched_getscheduler(pid);
    if (new_policy == -1) {
        perror("Policy Error");
    } else {
        print_policy(new_policy);
    }

    return 0;
}
