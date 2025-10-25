#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: String to convert
 *
 * Return: Integer value, or 0 if no numbers
 */
int _atoi(char *s)
{
	int i, sign, result, digit;

	i = 0;
	sign = 1;
	result = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (result > 0)
				result = result * 10 + digit;
			else
				result = result * 10 - digit;

			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		i++;
	}

	return (result * sign);
}
