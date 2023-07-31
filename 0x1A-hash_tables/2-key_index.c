#include "hash_tables.h"

/**
 * key_index - retrieves the index of a given key
 * @input_key: the key for which the index is needed
 * @table_size: the size of the hash table
 *
 * Return: the calculated index for the given key
 */
unsigned long int
key_index(const unsigned char *input_key, unsigned long int table_size)
{
	return (hash_djb2(input_key) % table_size);
}
