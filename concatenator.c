#include "shell.h"

/**
 * concat - concatanates a string
 * @dest: String to be concatanated onto
 * @src: string to be concatanate onto dest
 * 
 * Return: Concatanated string
*/

char *concat(char *dest, char *src)
{
	char *temp = NULL;

	temp = dest;

	dest = malloc(strlen(temp) + strlen(src) + 1);

	if (!dest)
	{
		dest = temp;
		return (dest);
	}

	strcpy(dest, temp);
	free(temp);
	strcat(dest, src);
	return(dest);
}
