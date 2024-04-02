#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * tokenize - Creates an array of tokens
 *
 * @array: The array to be initialized and filled with tokens
 * @buffer: The buffer to find tokens in
 * @delim: The character delimiter
 *
 * Description:
 *
 * |Free|	This function creates an array of char pointers to tokens in a string
 *		"buffer", so the only memory allocated by this function that you MUST
 *		free is the array itself with a call like "free(array)". Don't forget,
 *		this doesn't free the buffer itself, so be sure to free "buffer"
 *		separately, although these free calls can be done independently of
 *		each other, in any order.
 *
 * Return: The number of tokens in the array (or 0 on failure)
 */

int tokenize(char ***array, char *buffer, const char *delim)
{
	size_t i;
	int tokenNumber = 1;
	char *token = NULL;

	if (!buffer || buffer[0] == '\0')
	{
		return (0);
	}

	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == delim[0])
		{
			tokenNumber++;
		}
	}

	*array = malloc(sizeof(char *) * (tokenNumber + 1));

	if (!(*array))
	{
		return (0);
	}

	i = 0;

	token = strtok(buffer, delim);

	while (token != NULL)
	{
		(*array)[i] = strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	(*array)[i] = NULL;
	return (tokenNumber);
}
