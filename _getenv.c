#include "shell.h"

char *_getenv(char **environ, char *envVar)
{
	int i;
	char *tmp = NULL;

	tmp = malloc(strlen(envVar) + 2);

	strcpy(tmp, envVar);
	strcat(tmp, "=");

	for (i = 0; environ[i]; i++)
	{
		if (strstr(tmp, environ[i]))
		{
			free(tmp);
			return (environ[i]);
		}
	}
	free(tmp);
	return (NULL);
}
