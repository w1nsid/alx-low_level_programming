#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - Prints strings, followed by a new line.
 * @separator: The string to be printed between strings.
 * @n: The number of strings passed to the function.
 * @...: A variable number of strings to be printed.
 *
 * Description: If separator is NULL, it is not printed.
 *              If one of the strings if NULL, (nil) is printed instead.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings_to_print;
	char *str;
	unsigned int str_index;

	va_start(strings_to_print, n);

	for (str_index = 0; str_index < n; str_index++)
	{
		str = va_arg(strings_to_print, char *);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (str_index != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");

	va_end(strings_to_print);
}
