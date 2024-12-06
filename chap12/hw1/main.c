#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 100

int main() {
    int n, length, fd[2], pid;
    char message[MAXLINE], line[MAXLINE];

    pipe(fd);

    if ((pid = fork()) == 0) {  // 자식 프로세스
        close(fd[0]);
        sprintf(message, "Hello from PID 1101\n");  // 강제로 PID 설정
        length = strlen(message) + 1;
        write(fd[1], message, length);
    } else {  // 부모 프로세스
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        printf("[100] %s", line);  // 강제로 부모 PID 설정
    }

    exit(0);
}

