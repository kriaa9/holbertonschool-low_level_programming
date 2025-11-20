#include "variadic_functions.h"

/**
 * print_all - Prints anything based on format
 * @format: List of types of arguments passed
 */
void print_all(const char * const format, ...)
{
    va_list args;
    char *str, *sep;
    int i;

    va_start(args, format);
    sep = "";
    i = 0;
    while (format && format[i])
    {
        switch (format[i])
        {
        case 'c':
            printf("%s%c", sep, va_arg(args, int));
            sep = ", ";
            break;
        case 'i':
            printf("%s%d", sep, va_arg(args, int));
            sep = ", ";
            break;
        case 'f':
            printf("%s%f", sep, va_arg(args, double));
            sep = ", ";
            break;
        case 's':
            str = va_arg(args, char *);
            if (!str)
                str = "(nil)";
            printf("%s%s", sep, str);
            sep = ", ";
            break;
        }
        i++;
    }
    printf("\n");
    va_end(args);
}
