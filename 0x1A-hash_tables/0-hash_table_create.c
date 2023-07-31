#include "hash_tables.h"

/**
 * hash_table_create - Establishes a hash table
 * @size: Dimension of the array
 *
 * Return: Pointer to the newly formed hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	unsigned long int counter;

	new_table = malloc(sizeof(hash_table_t));
	if (new_table == NULL)
		return (NULL);
	new_table->size = size;
	new_table->array = malloc(size * sizeof(hash_node_t *));
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}
	for (counter = 0; counter < size; counter++)
		new_table->array[counter] = NULL;
	return (new_table);
}
