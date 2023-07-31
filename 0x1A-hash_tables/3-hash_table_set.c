#include "hash_tables.h"

/**
 * make_hash_node - constructs a new hash node
 * @key: the key associated with the node
 * @value: the value associated with the node
 *
 * Return: the newly constructed node, or NULL if an error occurred
 */
hash_node_t *make_hash_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

/**
 * hash_table_set - associates a key with a value in the hash table
 * @ht: the hash table to add the element to
 * @key: the key for the value
 * @value: the value to store
 *
 * Return: 1 if successful, 0 if not
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *new_hash_node, *temp;
	char *value_copy;

	if (ht == NULL || ht->array == NULL || ht->size == 0 || key == NULL
		|| strlen(key) == 0 || value == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[idx];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			value_copy = strdup(value);
			if (value_copy == NULL)
				return (0);
			free(temp->value);
			temp->value = value_copy;
			return (1);
		}
		temp = temp->next;
	}
	new_hash_node = make_hash_node(key, value);
	if (new_hash_node == NULL)
		return (0);
	new_hash_node->next = ht->array[idx];
	ht->array[idx] = new_hash_node;
	return (1);
}
