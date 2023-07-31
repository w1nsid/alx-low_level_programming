#include "hash_tables.h"

/**
 * hash_table_delete - removes a hash table
 * @ht: hash table to be removed
 *
 * Return: none
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int idx;
	hash_node_t *next_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (idx = 0; idx < ht->size; idx++)
	{
		while (ht->array[idx] != NULL)
		{
			next_node = ht->array[idx]->next;
			free(ht->array[idx]->key);
			free(ht->array[idx]->value);
			free(ht->array[idx]);
			ht->array[idx] = next_node;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->size = 0;
	free(ht);
}
