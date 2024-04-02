#include "shell.h"
#include <sys/wait.h>

/**
 * fork_process_and_execute - forks process and executes
 * @path: path name of the program to be run
 * @argv: Arguments sent to the shell
 * @environ: list of environmental variables
 * 
 * Return: status that child exited with
*/

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
