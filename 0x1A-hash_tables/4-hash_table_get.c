#include "hash_tables.h"

/**
 * hash_table_get - fetches a value linked with a key
 * @ht: table from where the value needs to be fetched
 * @key: key linked to the desired value
 *
 * Return: value linked with the key, or NULL if the key doesn't exist
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *temp_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0 || key == NULL
		|| strlen(key) == 0)
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	temp_node = ht->array[idx];
	while (temp_node != NULL)
	{
		if (strcmp(temp_node->key, key) == 0)
			return (temp_node->value);
		temp_node = temp_node->next;
	}
	return (NULL);
}
