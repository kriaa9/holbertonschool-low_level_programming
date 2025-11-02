#include "main.h"

/**
 * _strspn - Gets length of prefix substring
 * @s: String to search
 * @accept: String of accepted characters
 *
 * Return: Number of bytes in initial segment of s from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count, i, j;
	int found;

	count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		found = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}
		if (found)
			count++;
		else
			break;
	}

	return (count);
}
