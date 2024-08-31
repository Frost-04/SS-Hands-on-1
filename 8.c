
/*
============================================================================
Name : 8.c
Author : Gaurav Verma
Description :  Write a program to open a file in read only mode, read line by line and display each line as it is read.
                Close the file when end of file is reached.

Date: 19th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argv, char *argc[]) {
    int fd1 = open(argc[1], O_RDONLY);
    if (fd1 == -1) {
        perror("Error!");
        close(fd1);
        return 0;
    }
    char c, content[1024];
    int i = 0, j = 0;
    while (read(fd1, &content[i], 1)) {
        if (content[i] == '\n') {
            for (j = 0; content[j] != '\n'; j++) printf("%c", content[j]);
            printf("\n");
            content[j] = 'a';
            i = 0;
        } else {
            i++;
        }
    }
    close(fd1);
}
