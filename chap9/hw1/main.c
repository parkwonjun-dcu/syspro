#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 256
#define MAX_ARGS 128

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        char *args[MAX_ARGS];
        char *token;
        int i = 0;

        token = strtok(command, " ");
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        execvp(args[0], args);
        fprintf(stderr, "Failed to execute command: %s\n", command);
        exit(1);
    } else {
        printf("[%d] Parent process start\n", getpid());
        wait(&status);
        printf("[%d] Parent process end\n", getpid());
    }
}

int main() {
    char line[MAX_LINE];
    char *command;

    while (1) {
        printf("Pls input cmd : ");
        fgets(line, sizeof(line), stdin);

        command = strtok(line, "\n");
        if (strcmp(command, "exit") == 0) {
            break;
        }

        if (strchr(command, '&')) {
            *strchr(command, '&') = '\0';
            execute_command(command);
        } else {
            execute_command(command);
        }
    }

    return 0;
}
