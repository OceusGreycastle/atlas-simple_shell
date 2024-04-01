#include "shell.h"

/**
 * _getenv - gets the environment for the given input
 * @environ: environmental variables
 * @envVar: Variable for referencing the environ
 * 
 * Return: The token number
*/

char *_getenv(char **environ, char *envVar)
{
	int i;
	char *tmp = NULL;

	tmp = malloc(strlen(envVar) + 2);

	strcpy(tmp, envVar);
	strcat(tmp, "=");

	for (i = 0; environ[i]; i++)
	{

		if (strstr(environ[i], tmp))
		{
			free(tmp);
			return (environ[i]);
		}
	}
	free(tmp);
	return (NULL);
}
