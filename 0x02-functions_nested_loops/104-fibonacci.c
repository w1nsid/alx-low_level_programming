#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 * Return: 0
 */

int main(void)
{
	int i;
	long int a, b, c;

	a = 1;
	b = 2;
	printf("%ld, %ld, ", a, b);
	for (i = 0; i < 96; i++)
	{
		c = a + b;
		a = b;
		b = c;
		printf("%ld", c);
		if (i != 95)
		{
			printf(", ");
		}
	}
	printf("\n");
	return (0);
}
