#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * generate_key - Generates a key based on a username for crackme5
 * @username: The username for which to generate the key
 *
 * Return: The generated key
 */
char *generate_key(const char *username)
{
	unsigned int i, value;
	size_t len, sum;
	char *charset = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char *key = malloc(7 * sizeof(char));
	if (key == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}

	len = strlen(username);
	key[0] = charset[(len ^ 59) & 63];

	for (i = 0, sum = 0; i < len; i++)
		sum += username[i];
	key[1] = charset[(sum ^ 79) & 63];

	for (i = 0, value = 1; i < len; i++)
		value *= username[i];
	key[2] = charset[(value ^ 85) & 63];

	for (value = username[0], i = 0; i < len; i++)
		if ((char)value <= username[i])
			value = username[i];
	srand(value ^ 14);
	key[3] = charset[rand() & 63];

	for (value = 0, i = 0; i < len; i++)
		value += username[i] * username[i];
	key[4] = charset[(value ^ 239) & 63];

	for (value = 0, i = 0; (char)i < username[0]; i++)
		value = rand();
	key[5] = charset[(value ^ 229) & 63];

	return key;
}

/**
 * main - Entry point of the program
 * @argc: Number of arguments passed
 * @argv: Array of arguments passed to the program
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char *key;

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return 1;
	}

	key = generate_key(argv[1]);
	printf("%s\n", key);
	free(key);

	return 0;
}
