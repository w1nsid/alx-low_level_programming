#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * main - Prints a string to stderr
 *
 * Return: Always 1 (Success)
 */

int main(void)
{
	char *m = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	const int stderr_fd = 2;
	int i;

	for (i = 0; i < strlen(m); i++)
	{
		write(stderr_fd, &m[i], 1);
	}
}
