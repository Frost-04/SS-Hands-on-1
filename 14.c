/*
============================================================================
Name : 14.c
Author : Gaurav Verma
Description :  Write a program to find the type of a file.
                a. Input should be taken from command line.
                b. program should be able to identify any type of a file. 
Date: 21st Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>

int main(int argv, char *argc[]) {
    struct stat stats;
    printf("File type is: ");

    if (S_ISREG(stats.st_mode))
        printf("The file is regular file.\n");

    else if (S_ISDIR(stats.st_mode))
        printf("The file is directory.\n");

    else if (S_ISLNK(stats.st_mode))
        printf("The file is symbolic link.\n");

    else if (S_ISCHR(stats.st_mode))
        printf("The file is character device.\n");

    else if (S_ISBLK(stats.st_mode))
        printf("The file is block device.\n");

    else if (S_ISFIFO(stats.st_mode))
        printf("The file is FIFO/pipe.\n");

    else if (S_ISSOCK(stats.st_mode))
        printf("The file is socket.\n");

    else
        printf("The file type is unknown.\n");

    return 0;
}


//output sample:-

// The file is regular file.
