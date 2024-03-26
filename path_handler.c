#include "shell.h"

char **path_handler(char **environ, char *argv)
{
	char **paths = NULL;
	char *pathenv = NULL;
	char *path = NULL;
	char *temp = NULL;
	int i;

	if (!environ)
	{
		return (NULL);
	}

	pathenv = _getenv(environ, "PATH");

	path = malloc(strlen(pathenv) - strlen("PATH"));

	if (!path)
	{
		return (NULL);
	}

	strcpy(path, pathenv + 5);

	tokenize(&paths, path, ":");

	return (array);
}
