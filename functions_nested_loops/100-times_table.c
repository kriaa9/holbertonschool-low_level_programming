#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0
 * @n: The times table to print
 *
 * Return: void
 */
void print_times_table(int n)
{
    int row, col, product;

    if (n < 0 || n > 15)
	return;

    for (row = 0; row <= n; row++)
    {
	for (col = 0; col <= n; col++)
	{
	    product = row * col;

	    if (col == 0)
	    {
		_putchar(product + '0');
	    }
	    else if (product < 10)
	    {
		_putchar(',');
		_putchar(' ');
		_putchar(' ');
		_putchar(' ');
		_putchar(product + '0');
	    }
	    else if (product < 100)
	    {
		_putchar(',');
		_putchar(' ');
		_putchar(' ');
		_putchar((product / 10) + '0');
		_putchar((product % 10) + '0');
	    }
	    else
	    {
		_putchar(',');
		_putchar(' ');
		_putchar((product / 100) + '0');
		_putchar(((product / 10) % 10) + '0');
		_putchar((product % 10) + '0');
	    }
	}
	_putchar('\n');
    }
}
