 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 #define maxline 100

 int main( )
 {
    int n, length, fd[2], pid;
    char message[maxline], line[maxline];

    pipe(fd);    

	if((pid = fork())== 0) { 
		close(fd[0]);
		sprintf(message,"hello frome pid %d\n", getpid());
		length = strlen(message)+1;
		write(fd[1],message,length);	
	}
	else { //parent
		close(fd[1]);
		n = read(fd[0],line, maxline);
		printf("[%d] %s" ,getpid(), line);
	}
	exit(0);
 }
	

