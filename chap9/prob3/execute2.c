#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( ) 
{
   printf("Parent process Start \n");
   if (fork( ) == 0) {
      execl("/bin/echo", "echo", "hello", NULL);
      fprintf(stderr,"First Fail"); 
      exit(1);
   }
  if (fork( ) == 0) {
      execl("/bin/date", "date", NULL);
      fprintf(stderr,"Second Fail"); 
      exit(2);
  }

   if (fork( ) == 0) {
      execl("/bin/ls","ls", "-l", NULL);
      fprintf(stderr,"Third Fail"); 
      exit(3);
   }
   printf("Parent process End \n");
}

