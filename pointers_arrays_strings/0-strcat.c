#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string to append
 *
 * Return: Pointer to resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int dest_len, i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return (dest);
}
