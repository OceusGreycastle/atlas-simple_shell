#include "shell.h"
#include <string.h>

/**
 * path_handler - Checks for the given path and returns it
 * @environ: environmental variables
 * @argv: array of pointers to arguements sent to the shell
 * 
 * Return: returns the full path name for the function to be run
*/

char *path_handler(char **environ, char *argv[])
{
	char **paths = NULL;
	char *pathenv = NULL;
	char *path = NULL;
	char *pathsString = NULL;
	char *file = argv[0];
	int i;

	if (!environ || !file)
	{
		return (NULL);
	}

	pathenv = _getenv(environ, "PATH");

	pathsString = malloc(strlen(pathenv) - strlen("PATH"));

	if (!pathsString)
	{
		return (NULL);
	}

	strcpy(pathsString, pathenv + 5);

	tokenize(&paths, pathsString, ":");

	for (i = 0; paths[i]; i++)
	{
		paths[i] = concat(paths[i], "/");
		paths[i] = concat(paths[i], file);

		if (access(paths[i], F_OK) == 0)
		{
				path = strdup(paths[i]);
				break;
		}

	}

	free(pathsString);
	for (i = 0; paths[i]; i++)
	{
		free(paths[i]);
	}
	free(paths);

	return (path);
}
