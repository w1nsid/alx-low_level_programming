#include <stdio.h>
#include <string.h>
/**
 * main - Prints a string fwrite
 *
 * Return: Always 1 (Success)
 */

int main(void)
{
	char *m = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	size_t len = strlen(m);

	fwrite(m, sizeof(char), len, stderr);
	return (1);
}
