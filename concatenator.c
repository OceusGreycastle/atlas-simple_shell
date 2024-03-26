#include "shell.h"

void concat(char *dest, char *src)
{
	char *temp = NULL;

	temp = dest;

	dest = malloc(strlen(temp) + strlen(src) + 1);

	if (!dest)
	{
		dest = temp;
		return (NULL);
	}

	strcpy(dest, temp);
	strcat(dest, src);

	return (dest);
}
