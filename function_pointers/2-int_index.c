#include "function_pointers.h"

/**
 * int_index - Searches for an integer using comparison function
 * @array: Array of integers
 * @size: Number of elements in array
 * @cmp: Pointer to comparison function
 *
 * Return: Index of first element for which cmp does not return 0,
 *         -1 if no match or size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}

	return (-1);
}
