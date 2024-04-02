#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int tokenize(char **array[], char *buffer, const char *delim);
char *_getenv(char **environ, char *envVar);
char *path_handler(char **environ, char *argv[]);
char *concat(char *dest, char *src);
int isbuiltin(char *buffer, char **environ);
int fork_process_and_execute(char *path, char *argv[], char *environ[]);

#endif
