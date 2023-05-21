#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to flip
 * to convert one number to another
 * @num1: Input number 1
 * @num2: Input number 2
 * Return: Number of bits to flip
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	unsigned int count = 0;
	int position = 0;

	for (; position <= 63; position++)
	{
		if (((num1 ^ num2) >> position) & 1)
			count++;
	}

	return (count);
}
