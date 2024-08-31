/*
============================================================================
Name : 7.c
Author : Gaurav Verma
Description : Write a program to copy file1 into file2 ($cp file1 file2)
Date: 19th Aug, 2024.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(int argv,char *argc[]){
	char copier;
	int fd1=open(argc[1],O_RDONLY);
	if(fd1==-1){
		perror("Source Error!");
		close(fd1);
		return 0;
	}
	int fd2=open(argc[2],O_WRONLY|O_CREAT,0700);
	if(fd2==-1){
		perror("Destination File Error!");
		close(fd2);
		return 0;
	}


	while(read(fd1,&copier,1)){
		write(fd2,&copier,1);
	}

	close(fd1);
	close(fd2);
	printf("SUCCESS");
	return 0;
}
