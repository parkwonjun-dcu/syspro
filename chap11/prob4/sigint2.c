#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/* -> signal.h
struct sigaction {
	void (*sa_handler)(int);       	
	void (*sa_sigaction)(int, siginfo_t *, void *); 
	sigset_t sa_mask; 		
	int sa_flags; 
}
*/

struct sigaction newact;
struct sigaction oldact;

 void sigint_handler(int signo)
 {
     printf( "signal number %d\n", signo);
     printf( "press it again, Exit.\n");
     sigaction(SIGINT, &oldact, NULL);
 }

int main( void)
{
     newact.sa_handler = sigint_handler;  
	 sigfillset(&newact.sa_mask); 
   
	 sigaction(SIGINT, &newact, &oldact); 
	     while(1 ) {
        printf( "Type Ctrl-C!\n");
        sleep(1);
     }
 }


