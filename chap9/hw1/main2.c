#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void execute_command(char *cmd) {
    char *args[MAX_ARGS];
    int arg_count = 0;
    int background = 0;

    char *token = strtok(cmd, " ");
    while (token != NULL && arg_count < MAX_ARGS - 1) {
        if (strcmp(token, "&") == 0) {
            background = 1; // Enable background execution
        } else {
            args[arg_count++] = token;
        }
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    if (arg_count == 0) return;

    if (strcmp(args[0], "exit") == 0) {
        printf("Exiting shell.\n");
        exit(0);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {
        printf("[Child Process Started] PID: %d\n", getpid());
        execvp(args[0], args);
        perror("Command execution failed");
        exit(1);
    } else {
        printf("[Parent Process] Created child process %d\n", pid);
        if (!background) {
            int status;
            waitpid(pid, &status, 0);
            printf("[Child Process Exited] PID: %d (Exit Code: %d)\n", pid, WEXITSTATUS(status));
        } else {
            printf("[Parent Process] Background process %d running\n", pid);
        }
    }
}

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("[Shell] ");
        fflush(stdout);

        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        printf("[Parent Process] Command execution started\n");
        execute_command(input);
        printf("[Parent Process] Command execution ended\n");
    }

    return 0;
}

