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
	const char *m1 = "and that piece of art is";
	const char *m2 = "useful\" - Dora Korpar, 2015-10-19\n";
	const int message_length = strlen(m1) + strlen(m2);
	const int stderr_fd = 2;
	char m[message_length];

	strcpy(m, m1);
	strcat(m, m2);

	for (int i = 0; i < message_length; i++)
	{
		write(stderr_fd, &m[i], 1);
	}

	return (1);
}
