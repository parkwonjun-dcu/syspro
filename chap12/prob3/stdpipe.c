#include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 #define MAXLINE 100

 int main( )
 {
    int n, length, fd[2], pid;
  	char line[MAXLINE];
    pipe(fd);    

	if((pid = fork())== 0) { //child
		close(fd[0]);
		dup2(fd[1],1);
		close(fd[1]);
		printf("Hello! pipe\n");
		printf("Bye! pipe\n");
	}
	else { //parent
		close(fd[1]);
		printf("The result from child process\n");
			while((n = read(fd[0],line,MAXLINE))>0){
			write(STDOUT_FILENO,line,n);
		}
	}
	exit(0);
 }
	

