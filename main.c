#include "shell.h"

/**
 * main - this function runs the shell and it's workings directly
 * @argc: counts arguments and stores it as an int
 * @argv: array of pointers to the array of character objects
 * @environ: the environment for our variables
 * 
 * Description: This function refrences other
 * functions such as isbuiltin and tokenize
 * to run processes through the shell
 * 
 * Return: 0
*/

int main(int argc, char *argv[], char **environ)
{
	int myArgc = 0, i;
	size_t size;
	ssize_t chars_read;
	char **myArgv;
	char *buffer;

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
		
		if (!isbuiltin(buffer, environ))
		{
			myArgc = tokenize(&myArgv, buffer, " ");

			path = path_handler(environ, myArgv);

			if (!path)
			{
				perror("Error: ");
			}
			else {
				fork_process(path);

				for (i = 0; array[i]; i++)
				{
					free(myArgv[i]);
				}
			}
			free(array);
		}
		free(buffer);
	}

	return (0);
}
