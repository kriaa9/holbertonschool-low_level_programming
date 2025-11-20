#include "variadic_functions.h"

/**
 * print_all - Prints anything based on format
 * @format: List of types of arguments passed
 */
void print_all(const char * const format, ...)
{
    va_list args;
    int i = 0, j;
    char *str, *sep = "";

    va_start(args, format);
    while (format && format[i])
    {
        j = 0;
        while (j < 4)
        {
            if (j == 0 && format[i] == 'c')
                printf("%s%c", sep, va_arg(args, int));
            if (j == 1 && format[i] == 'i')
                printf("%s%d", sep, va_arg(args, int));
            if (j == 2 && format[i] == 'f')
                printf("%s%f", sep, va_arg(args, double));
            if (j == 3 && format[i] == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(nil)";
                printf("%s%s", sep, str);
            }
            j++;
        }
        if (format[i] == 'c' || format[i] == 'i' || 
            format[i] == 'f' || format[i] == 's')
            sep = ", ";
        i++;
    }
    va_end(args);
    printf("\n");
}
