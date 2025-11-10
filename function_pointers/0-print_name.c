#include "function_pointers.h"

/**
 * print_name - Prints a name using a function pointer
 * @name: Name to print
 * @f: Pointer to function that prints the name
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
