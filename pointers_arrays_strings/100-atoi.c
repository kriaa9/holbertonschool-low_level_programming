#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: String to convert
 *
 * Return: Integer value, or 0 if no numbers
 */
int _atoi(char *s)
{
	int i, sign, result, started;

	i = 0;
	sign = 1;
	result = 0;
	started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			if (!started)
				sign *= -1;
		}
		else if (s[i] == '+')
		{
			if (!started)
				sign *= 1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			result = result * 10 - (s[i] - '0');
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		else if (started)
			break;
		i++;
	}
	if (sign > 0)
		result = -result;
	return (result);
}
