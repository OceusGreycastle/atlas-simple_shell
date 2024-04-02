#include "shell.h"
#include <sys/wait.h>

int fork_process_and_execute(char *path, char *argv[], char *environ[])
{
	pid_t myPid;
	int status;

	myPid = fork();

	if (myPid == 0)
	{
		execve(path, argv, environ);
		exit(EXIT_SUCCESS);
	} else
	{
		wait(&status);
	}
	return (status);
}
