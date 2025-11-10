#include "3-calc.h"

/**
 * op_add - Returns sum of a and b
 * @a: First integer
 * @b: Second integer
 *
 * Return: Sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Returns difference of a and b
 * @a: First integer
 * @b: Second integer
 *
 * Return: Difference of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Returns product of a and b
 * @a: First integer
 * @b: Second integer
 *
 * Return: Product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Returns division of a by b
 * @a: First integer
 * @b: Second integer
 *
 * Return: Result of division
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - Returns remainder of division of a by b
 * @a: First integer
 * @b: Second integer
 *
 * Return: Remainder of division
 */
int op_mod(int a, int b)
{
	return (a % b);
}
