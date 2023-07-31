#include "hash_tables.h"

/**
 * hash_table_print - displays a hash table
 * @ht: hash table to be displayed
 *
 * Return: none
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int counter;
	hash_node_t *temp_node;
	char print_flag = 0; /* Remains 0 till no data has been printed */

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	for (counter = 0; counter < ht->size; counter++)
	{
		temp_node = ht->array[counter];
		while (temp_node != NULL)
		{
			if (print_flag == 1)
				printf(", ");
			printf("'%s': '%s'", temp_node->key, temp_node->value);
			print_flag = 1;
			temp_node = temp_node->next;
		}
	}
	printf("}\n");
}
