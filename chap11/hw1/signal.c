#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

struct sigaction newact;
struct sigaction oldact;
void sigint_handler(int signo); 
void alarmHandler();

int main( void)
{
     newact.sa_handler = sigint_handler;  
	 sigfillset(&newact.sa_mask);
	 sigaction(SIGINT, &newact, &oldact);

	while (1) {
      printf("Type Ctrl-C!\n");
	  sleep(1);
    }
}

void sigint_handler(int signo)
{
  signal(SIGALRM, alarmHandler);
  alarm(5);    
  short i = 0;
  while (1) {
    sleep(1);
    i++;
    printf("%d second\n", i);
  }
  printf("end\n");
  sigaction(SIGINT, &oldact, NULL);
}

void alarmHandler(int signo)
{
   printf("Wake up\n");
   exit(0);
}
