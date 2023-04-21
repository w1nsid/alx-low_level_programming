#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Calculates the sum of a variable number of parameters.
 * @n: The number of parameters to sum.
 * @...: A variable number of paramters to calculate the sum of.
 *
 * Return: If n == 0 - 0.
 *         Otherwise - the sum of all parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int arg_index, sum = 0;

	va_start(ap, n);

	for (arg_index = 0; arg_index < n; arg_index++)
		sum += va_arg(ap, int);

	va_end(ap);

	return (sum);
}
