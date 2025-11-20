#include "variadic_functions.h"

/**
 * print_char - Prints a char with separator
 * @sep: Separator string
 * @args: Argument list
 */
void print_char(char *sep, va_list args)
{
    printf("%s%c", sep, va_arg(args, int));
}

/**
 * print_int - Prints an int with separator
 * @sep: Separator string
 * @args: Argument list
 */
void print_int(char *sep, va_list args)
{
    printf("%s%d", sep, va_arg(args, int));
}

/**
 * print_float - Prints a float with separator
 * @sep: Separator string
 * @args: Argument list
 */
void print_float(char *sep, va_list args)
{
    printf("%s%f", sep, va_arg(args, double));
}

/**
 * print_string - Prints a string with separator
 * @sep: Separator string
 * @args: Argument list
 */
void print_string(char *sep, va_list args)
{
    char *str;

    str = va_arg(args, char *);
    if (str == NULL)
        str = "(nil)";
    printf("%s%s", sep, str);
}

/**
 * print_all - Prints anything based on format
 * @format: List of types of arguments passed
 */
void print_all(const char * const format, ...)
{
    va_list args;
    int i = 0;
    char *sep = "";

    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] == 'c')
        {
            print_char(sep, args);
            sep = ", ";
        }
        if (format[i] == 'i')
        {
            print_int(sep, args);
            sep = ", ";
        }
        if (format[i] == 'f')
        {
            print_float(sep, args);
            sep = ", ";
        }
        if (format[i] == 's')
        {
            print_string(sep, args);
            sep = ", ";
        }
        i++;
    }
    va_end(args);
    printf("\n");
}
