#include "main.h"

/**
 * check_prime - Helper function to check divisibility
 * @n: Number to check
 * @divisor: Current divisor to test
 *
 * Return: 1 if prime, 0 if not
 */
int check_prime(int n, int divisor)
{
	if (divisor * divisor > n)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (check_prime(n, divisor + 1));
}

/**
 * is_prime_number - Checks if a number is prime
 * @n: Number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	if (n == 2)
		return (1);

	if (n % 2 == 0)
		return (0);

	return (check_prime(n, 3));
}
