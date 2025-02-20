#include "shell.h"
#include <stdio.h>

/**
 * main - Starts shell and takes user input and parses it
 * @argc: Counts the number of arguements sent to the shell
 * @argv: array of pointers to the arguments sent to shell
 * @environ: environmental variables
 * 
 * Description: This function refrences other
 * functions such as isbuiltin and tokenize
 * to run processes through the shell
 * 
 * Return: 0
*/

int main(int argc, char *argv[], char **environ)
{
	int i;
	size_t size;
	ssize_t chars_read;
	char **myArgv;
	char *buffer;
	char *path = NULL;

	while (1)
	{
		myArgv = NULL;
		buffer = NULL;
		size = 0;
		
		if (argv && argc && environ)
		{
			printf("$ ");
		}

		chars_read = getline(&buffer, &size, stdin);

		if (!chars_read)
		{
			break;
		}

		i = 0;

		while (buffer[i] != '\n')
		{
			i++;
		}

		buffer[i] = '\0';
		
		if (!isbuiltin(buffer, environ))
		{
			tokenize(&myArgv, buffer, " ");

			path = path_handler(environ, myArgv);

			if (!path)
			{
				perror("Error: ");
			} else
			{
				fork_process_and_execute(path, myArgv, environ);

				for (i = 0; myArgv[i]; i++)
				{
					free(myArgv[i]);
				}
			}
			free(myArgv);
		}
		free(buffer);
	}

	return (0);
}
