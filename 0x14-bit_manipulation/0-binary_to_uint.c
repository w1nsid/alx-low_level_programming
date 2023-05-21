#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer
 * @b: const char pointer to the binary string
 * Return: Converted unsigned integer value
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int exponent = 1, index = 0;

	if (b == NULL)
		return (0);

	while (b[index + 1])
	{
		if (b[index] != '0' && b[index] != '1')
			return (0);
		index++;
	}

	while (index >= 0)
	{
		result += ((b[index] - '0') * exponent);
		exponent *= 2;
		index--;
	}

	return (result);
}
