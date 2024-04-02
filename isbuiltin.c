#include "shell.h"

/**
 * isbuiltin - function for calling our builtin functions
 * @buffer: user input
 * @environ: environmental variables
 * 
 * Description: If 'exit' is sent to the shell then shell 
 * terminates its own process
 * 
 * Return: if not builtin return 0, if builtin return 1
*/

int isbuiltin(char *buffer, char **environ)
{
	int i;
	if (!strcmp(buffer, "exit"))
	{
		exit(EXIT_SUCCESS);
	}

	if (!strcmp(buffer, "env"))
	{
		for (i = 0; environ[i]; i++)
		{
			printf("%s\n", environ[i]);
		}
		return (1);
	}
	return (0);
}
