#include <stdio.h>
#include <string.h>   // for strlen
#include <stdlib.h>   // for exit

int main() 
{
	int pipes[2];
	int r;
	r = pipe(pipes);
	if (r < 0) 
	{
		fprintf(stderr, "pipe failed\n\n");// stderr is a FILE* variable for the standard error file (terminal)
		exit(2);
	}
	// use pipes[0] to read and pipes[1] to write
	
	int pid = fork();
	if (pid > 0) 
	{  // PARENT
		char *message = "Howdy";
		// close(pipes[0]);  // not needed
		printf("parent writing '%s' with strlen=%d\n", message, strlen(message));
		
		r = write(pipes[1], message, strlen(message)+1);
		if (r < 0) 
		{
			fprintf(stderr, "parent: write failed\n\n");
			exit(3);
		}
		
		printf("parent wrote %d bytes\n", r);
	}
	else if (pid == 0) 
	{ // CHILD
		char buff[1000];
		// close(pipes[1]);     // not actually needed
		printf("child reading...\n");
		r = read(pipes[0], buff, sizeof(buff));
		printf("child read %d bytes: '%s'\n", r, buff);
		// terminating \0 char not displayed by the terminal, but is essential 
	}
	else 
	{
		fprintf(stderr, "FORK FAILED\n\n");
		return 1;
	}
	// both parent and child process get here:
	return 0;
}