#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLINE 256
main() {
    int fd1, fd2, n;
    char inmsg[MAXLINE];
    fd1 = open("./chatfifo1", O_RDONLY);
    fd2 = open("./chatfifo2", O_WRONLY);
    if(fd1 == -1 || fd2 == -1) {
        perror("open");
        exit(1);
    }

    printf("*client start");
    while(1) {
        n = read(fd1, inmsg, MAXLINE); 
        printf("[server] -> %s\n", inmsg);
        printf("[client] : ");
        fgets(inmsg, MAXLINE, stdin);
        write(fd2, inmsg, strlen(inmsg)+1); 
    }
}

