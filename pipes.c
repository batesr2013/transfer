#include <stdio.h>
#define _XOPEN_SOURCE 700
#include <string.h>   // for strlen
#include <unistd.h>
#include <stdlib.h>   // for exit
#include <stdarg.h>
#include <errno.h>
static void error_systemError( const char *fmt, ... );

int main(void) 
{
	int pipes1[2];
	int pipes2[2];
	printf(" batesr2013@fau.edu ");
	//int r;
	//r = pipe(pipes);
	
	pid_t proc1;
	pid_t proc2;
	
	if (pipe(pipes1) == -1 )
	{
		error_systemError(" pipe1 has failed ");
	}
	if ((proc1 = fork()) < 0)
	{
		error_systemError(" fork1 has failed ");
	}
	
	if (proc1 == 0)
	{
		dup2( pipes1[1], STDOUT_FILENO);
		close( pipes1[0] );
		close( pipes1[1] );
		execlp( "ps", "ps", "-ef", (char *) 0);
		error_systemError( " ps failed ");
	}
	if (pipe(pipes2) == -1)
	{
		error_systemError(" pipe2 has failed ");
	}
	if ((proc2 = fork()) < 0)
	{
		error_systemError(" fork2 has failed ");
	}
	if (proc2 == 0)
	{
		dup2( pipes1[0], STDIN_FILENO);
		close( pipes1[0] );
		close( pipes1[1] );
		dup2( pipes2[1], STDOUT_FILENO);
		close( pipes2[0] );
		close( pipes2[1] );
		execlp( "grep", "grep", "root", (char *) 0);
		error_systemError( "grep failed");
	}
	else
	{
		close( pipes1[0] );
		close( pipes1[1] );
		dup2(pipes2[0], STDIN_FILENO);
		close(pipes2[0]);
		close(pipes2[1]);
		execlp("wc", "wc", (char *) 0);
		error_systemError("wc failed");
	}
	
}
static void error_systemError( const char *fmt, ... )
{
	int ern =errno;
	va_list arguments;
	vfprintf(stderr, fmt, arguments);
	va_end(arguments);
	if(ern != 0)
	{
		fprintf(stderr, "(%d : %s)", ern, strerror(ern));
		putc('\n', stderr);
		exit(EXIT_FAILURE);
	}
}
	//if (r < 0) 
	//{
		//fprintf(stderr, "pipe failed\n\n");// stderr is a FILE* variable for the standard error file (terminal)
		//exit(2);
	//}
	// use pipes[0] to read and pipes[1] to write
	
	//int pid = fork();
	//if (pid > 0) 
	//{  // PARENT
		//char *message = "Howdy";
		// close(pipes[0]);  // not needed
		//printf("parent writing '%s' with strlen=%d\n", message, strlen(message));
		
		//r = write(pipes[1], message, strlen(message)+1);
		//if (r < 0) 
		//{
			//fprintf(stderr, "parent: write failed\n\n");
			//exit(3);
		//}
		
		//printf("parent wrote %d bytes\n", r);
	//}
	//else if (pid == 0) 
	//{ // CHILD
		//char buff[1000];
		//// close(pipes[1]);     // not actually needed
		//printf("child reading...\n");
		//r = read(pipes[0], buff, sizeof(buff));
		//printf("child read %d bytes: '%s'\n", r, buff);
		// terminating \0 char not displayed by the terminal, but is essential 
	//}
	//else 
	//{
		//fprintf(stderr, "FORK FAILED\n\n");
		//return 1;
	//}
	// both parent and child process get here:
	//return 0;
//}
