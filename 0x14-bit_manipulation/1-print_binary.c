#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned long int
 * @n: Input number
 * Return: None
 */
void print_binary(unsigned long int n)
{
	int index, flag = 0;
	unsigned long int current;

	for (index = 63; index >= 0; index--)
	{
		current = n >> index;

		if (current & 1)
		{
			_putchar('1');
			flag++;
		}
		else if (flag)
			_putchar('0');
	}
	if (!flag)
		_putchar('0');
}
