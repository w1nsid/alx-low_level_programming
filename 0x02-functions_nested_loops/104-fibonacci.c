#include <stdio.h>
#define MAX_DIGITS 200

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: 0
 */

int main(void)
{
	int i, j, k, carry;
	int fib[MAX_DIGITS] = {1};
	int prev[MAX_DIGITS] = {1};
	int prev2[MAX_DIGITS] = {1};

	printf("1");
	for (i = 1; i < 98; i++)
	{
		carry = 0;
		for (j = 0; j < MAX_DIGITS; j++)
		{
			fib[j] = prev[j] + prev2[j] + carry;
			carry = fib[j] / 10;
			fib[j] %= 10;
		}
		printf(", ");
		for (k = MAX_DIGITS - 1; k >= 0; k--)
		{
			if (fib[k] != 0)
				break;
		}
		for (; k >= 0; k--)
		{
			printf("%d", fib[k]);
		}
		for (j = 0; j < MAX_DIGITS; j++)
		{
			prev2[j] = prev[j];
			prev[j] = fib[j];
		}
	}
	printf("\n");
	return (0);
}
