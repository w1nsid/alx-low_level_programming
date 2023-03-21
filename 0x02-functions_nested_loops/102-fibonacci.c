#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 * numbers must be separated by comma followed by a space
 *
 * Return: 0
 */

int main(void)
{
	int i;
	long int a, b, c;

	a = 1;
	b = 2;
	printf("%ld, %ld, ", a, b);
	for (i = 0; i < 48; i++)
	{
		c = a + b;
		a = b;
		b = c;
		printf("%ld", c);
		if (i != 47)
		{
			printf(", ");
		}
	}
	printf("\n");
	return (0);
}
