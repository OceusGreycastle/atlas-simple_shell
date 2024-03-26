#include "shell.h"

char **path_handler(char **environ)
{
	char argc = 0;
	char **array = NULL;
	char *path = NULL;
	char *temp = NULL;

	if (!environ)
	{
		return (NULL);
	}

	temp = _getenv(environ);

	if (!temp)
	{
		return (NULL);
	}

	path = malloc(strlen(temp) + 1);
	if (!path)
	{
		return (NULL);
	}

	strcpy(path, temp);

	strtok(temp, "=");
	path = path[strlen(temp)];

	argc = tokenize(&array, path, ":");

	return (array);
}
