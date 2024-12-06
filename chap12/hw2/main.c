#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 100

void to_uppercase(char *str) { //lower -> upper
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    int fd[2]; 
    int pid1, pid2;
    char message[MAXLINE], line[MAXLINE];

   pipe(fd);

  printf(" parent process start!\n");	

    // first child process
    if ((pid1 = fork()) == 0) {
        close(fd[0]);
        printf("input string: ");
        fgets(message, MAXLINE, stdin);
        message[strcspn(message, "\n")] = '\0'; 
        write(fd[1], message, strlen(message) + 1); 
        close(fd[1]); // 
        exit(0);
    }

    // sceond child process
    if ((pid2 = fork()) == 0) {
        close(fd[1]); // 
        read(fd[0], line, MAXLINE); 
        to_uppercase(line); 
        printf("Converted to uppercase: %s\n", line);
        close(fd[0]); 
        exit(0);
    }

    close(fd[0]);
    close(fd[1]);
	wait(NULL); 
	wait(NULL);
	return 0;
}

