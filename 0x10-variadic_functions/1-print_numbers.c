#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Prints numbers, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 * @...: A variable number of numbers to be printed.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers_to_print;
	unsigned int number_index;

	va_start(numbers_to_print, n);

	for (number_index = 0; number_index < n; number_index++)
	{
		printf("%d", va_arg(numbers_to_print, int));

		if (number_index != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(numbers_to_print);
}
