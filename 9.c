/*
============================================================================
Name : 9.c
Author : Gaurav Verma
Description : Write a program to print the following information about a given file.
                a. inode
                b. number of hard links
                c. uid
                d. gid
                e. size
                f. block size
                g. number of blocks
                h. time of last access
                i. time of last modification
                j. time of last change
Date: 19th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
int main(int agrv, char *argc[]) {
    struct stat stats;
    stat(argc[1], &stats);
    printf("inode=%ld\n", stats.st_ino);
    printf("Number of hardlink=%ld\n", stats.st_nlink);
    printf("User id=%d\n", stats.st_uid);
    printf("Group id=%d\n", stats.st_gid);
    printf("otal size in bytes=%ld\n", stats.st_size);
    printf("Block size: %ld bytes\n", (long)stats.st_size);
    printf("Time of last access=%s", ctime(&stats.st_atime));
    printf("Time of last modification=%s", ctime(&stats.st_mtime));
    printf("Time of last change:=%s", ctime(&stats.st_ctime));
    return 0;
}