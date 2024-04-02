#include "shell.h"

/**
 * strdup - Takes a string and returns a duplicate of that string
 *
 * @src: The string to be duplicated
 *
 * Return: A duplicate of src
 */

char *strdup(const char *src) 
{
    size_t len = strlen(src) + 1;
    char *dst = malloc(len);
    if (dst == NULL) return NULL;
    memcpy(dst, src, len);
    return (dst);
}
