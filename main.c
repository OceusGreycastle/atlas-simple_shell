#include "shell.h"

int main(int argc, char *argv[], char **environ)
{
	int myArgc = 0, i;
	size_t size;
	ssize_t chars_read;
	char **array;
	char *buffer;

	while (1)
	{
		array = NULL;
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

		if (!strcmp(buffer, "quit\n"))
		{
			printf("==QUITTING SHELL==\n");
			free(buffer);
			return (0);
		}

		myArgc = tokenize(&array, buffer, " ");

		for (i = 0; i != 0; i++)
		{
			printf("%s\n", array[i]);
		}

		printf("%i\n", myArgc);

		free(buffer);
		free(array);
	}

	return (0);
}
