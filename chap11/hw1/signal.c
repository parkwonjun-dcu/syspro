#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void alarmHandler(int signo);
struct sigaction action;

void my_signal(int signum, void (*handler)(int)) {
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    if (sigaction(signum, &action, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
}

int main() {
    my_signal(SIGALRM, alarmHandler);
    alarm(5);  

    short i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }
    printf("end\n");
}

void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}

