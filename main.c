#include "shell.h"

int main(int argc, char *argv[], char **environ)
{
	int myArgc = 0, i;
	size_t size;
	ssize_t chars_read;
	char **myArgv;
	char *buffer;

	while (1)
	{
		myArgv = NULL;
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
		
		if (!isbuiltin(buffer, environ))
		{
			myArgc = tokenize(&myArgv, buffer, " ");

			path = path_handler(environ, myArgv);

			if (!path)
			{
				perror("Error: ");
			}
			else {
				fork_process(path);

				for (i = 0; array[i]; i++)
				{
					free(myArgv[i]);
				}
			}
			free(array);
		}
		free(buffer);
	}

	return (0);
}
