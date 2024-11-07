 #include <stdio.h>
 #include <unistd.h>

 
 int main()
 {    
     printf("my process : [%d] \n", getpid());
     printf("my parent process: [%d] \n", getppid());
 }

