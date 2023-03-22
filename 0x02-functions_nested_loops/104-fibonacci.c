#include <stdio.h>

int main(void)
{
	unsigned int a1 = 1, a2 = 2;
	unsigned int b1 = 0, b2 = 0, b3 = 0;
	int i;

	printf("%u, %u", a1, a2);

	for (i = 2; i < 98; i++)
	{
		b1 = 0;
		b2 = 0;
		b3 = 0;
		b1 += (a1 % 10) + (a2 % 10);
		b2 += (a1 / 10) + (a2 / 10);
		if (b1 >= 10)
		{
			b1 -= 10;
			b2 += 1;
		}
		b3 += (a2 / 10);
		if (b2 >= 10)
		{
			b2 -= 10;
			b3 += 1;
		}
		printf(", %u%u%u", b3, b2, b1);
		a1 = a2;
		a2 = (b3 * 100) + (b2 * 10) + b1;
	}

	printf("\n");
	return 0;
}