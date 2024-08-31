/*
============================================================================
Name : 11.c
Author : Gaurav Verma
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
			  descriptors and check whether the file is updated properly or not.
 					a. use dup
 					b. use dup2
 					c. use fcntl
Date: 20th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argv,char *argc[]){
	int fd=open(argc[1],O_RDWR|O_APPEND|O_CREAT);
	if (fd == -1) {
        perror("Error!");
        close(fd);
        return 0;
    }
	int duplicate1=dup(fd);//assigne next minimun file descriptor
	write(fd,"Original using original FD\n",28);
	write(duplicate1,"Writing using dup fd\n",22);
	int duplicate2=dup2(fd,10);// if 10 file descriptor is avalible than assign otherwise return -1
	write(duplicate2,"Writing using dup2 fd\n",23);
	int fcntlfd = fcntl(fd, 0, 5);//assigne fd greater than or equal to 5 
	write(fcntlfd,"Writing using fnctl dup fd\n",28);
	return 0;

}