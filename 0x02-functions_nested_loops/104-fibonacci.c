#include <stdio.h>

#define MAX_DIGITS 200

int main(void)
{
	int i, j, k, carry;
	int fib[MAX_DIGITS] = {1};
	int prev[MAX_DIGITS] = {1};
	int prev2[MAX_DIGITS] = {0};

	for (i = 2; i <= 98; i++)
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
	return 0;
}