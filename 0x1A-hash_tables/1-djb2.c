#include "hash_tables.h"

/**
 * hash_djb2 - application of the djb2 algorithm
 * @str: string utilized to produce hash value
 *
 * Return: resulting hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash_value;
	int character;

	hash_value = 5381;
	while ((character = *str++))
	{
		hash_value = ((hash_value << 5) + hash_value) + character;
	}
	return (hash_value);
}
