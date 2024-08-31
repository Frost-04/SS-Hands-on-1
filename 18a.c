/*
============================================================================
Name : 18a.c
Author : Gaurav Verma
Description :  Write a program to perform Record locking.
                                a. Implement write lock
                                b. Implement read lock
                                Create three records in a file. Whenever you access a particular record, first lock it then modify/access
                                to avoid race condition.
Date: 30th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int i, fd;
    struct {
        int train_num;
        int ticket_count;
    } db[3];
    for (i = 0; i < 3; i++) {
        db[i].train_num = i + 1;
        db[i].ticket_count = 0;
    }

    fd = open("18a.c_record.txt", O_RDWR | O_CREAT, 0700);

    if (fd == -1) {
        perror("Error!");
        close(fd);
        return 0;
    }
    write(fd, db, sizeof(db));
    close(fd);
}

//Output Sample:-

/*
Select train Number(1,2,3):
1
Before Entering into the critical section
Ticket count : 1
To book ticket, press Enter:
Booked
*/