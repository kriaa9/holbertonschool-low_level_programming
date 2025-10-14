#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints 0-9 using putchar only
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
		putchar(num + '0');
	putchar('\n');

	return (0);
}
