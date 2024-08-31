/*
============================================================================
Name : 25.c
Author : Gaurav Verma
Description : Write a program to create three child processes. The parent should wait for a particular child (use
              waitpid system call).
Date: 25th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int child_pids[3];
    for (int i = 0; i < 3; i++) {
        child_pids[i] = fork();
        if (child_pids[i] == 0) {
            printf("Child %d with PID %d started.\n", i + 1, getpid());
            switch (i) {
                case 0:
                    sleep(5);
                    break;
                case 1:
                    sleep(30);
                    break;
                case 2:
                    sleep(40);
                    break;
            }
            printf("Child %d with PID %d finished.\n", i + 1, getpid());
            return 0;
        } else
            sleep(1);
    }

    int childno;
    printf("Enter child to wait for: ");
    scanf("%d", &childno);

    int status;
    waitpid(child_pids[childno - 1], &status, 0);
    printf("Child %d with PID %d exited.\n", childno, child_pids[childno - 1]);

    return 0;
}
