#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(char *command) {
    char *args[100];
    int i = 0;

    args[i] = strtok(command, " ");
    while (args[i] != NULL) {
        args[++i] = strtok(NULL, " ");
    }

    execvp(args[0], args);
    perror("execvp failed");
    exit(1);
}

int main(int argc, char *argv[]) {
    char str[100];
    char *command1, *command2;
    int fd[2];

    if (argc > 1) {

        strcpy(str, argv[1]);
        for (int i = 2; i < argc; i++) {
            strcat(str, " ");
            strcat(str, argv[i]);
        }
    } else {
       
        printf("[shell] ");
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1] = '\0';
    }

    if (strchr(str, '|') != NULL) { 
        command1 = strtok(str, "|");
        command2 = strtok(NULL, "|");

        pipe(fd);

        if (fork() == 0) {
           
            dup2(fd[1], STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            execute_command(command1);
        } else {
           
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
            close(fd[1]);
            execute_command(command2);
        }
    } else {
        if (fork() == 0) {
         
            execute_command(str);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
