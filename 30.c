/*
============================================================================
Name : 30.c
Author : Gaurav Verma
Description : Write a program to run a script at a specific time using a Daemon process
Date: 31st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    time_t curr, dead;
    struct tm *deadline;

    time(&curr);
    deadline = localtime(&curr);

    // take time from terminal
    deadline->tm_hour = atoi(argv[1]);
    deadline->tm_min = 0;
    deadline->tm_sec = 0;
    if(argv[2])
        deadline->tm_min = atoi(argv[2]);
    if(argv[3])
        deadline->tm_sec = atoi(argv[3]);

    dead = mktime(deadline);

    int forkvar = fork();
    if (forkvar == 0) {

        setsid();
        do {
            time(&curr);
            printf("Inside the loop!\n");
            sleep(1);
        } while (difftime(dead, curr) > 0);
        printf("Exiting\n");
    } else {
        exit(0);
    }
}

//Output Sample:-

/*
Inside the loop!
Inside the loop!
Inside the loop!
Inside the loop!
Exiting
*/