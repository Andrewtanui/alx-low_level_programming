#include "main.h"
/**
 * _strncpy - Copies up to n characters from a string
 *
 * @dest: Pointer to the destination string
 * @src: Pointer to the source string
 * @n: Maximum number of characters to copy
 *
 * Return: Pointer to the resulting string dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int index = 0, src_len = 0;

	while (src[index++])
		src_len++;

	for (index = 0; src[index] && index < n; index++)
		dest[index] = src[index];

	for (index = src_len; index < n; index++)
		dest[index] = '\0';

	return (dest);
}

