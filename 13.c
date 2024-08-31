/*
============================================================================
Name : 13.c
Author : Gaurav Verma
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
              verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 20th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
void main()
{
    struct timeval timeout;
    fd_set readfd;
    FD_SET(0, &readfd);
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    int output = select(1, &readfd, NULL, NULL, &timeout);
    if (output == -1)
    {
        perror("Error occured");
    }
    else if (output == 0)
    {
        printf("Time out"); 
    }
    else
    {
        printf("Data entered");
    }
}