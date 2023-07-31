#include "hash_tables.h"

/**
 * Establishes a sorted hash table
 * @tableSize: The size of the hash table
 *
 * Return: Pointer to the newly created table, or NULL if unsuccessful
 */
shash_table_t *shash_table_create(unsigned long int tableSize)
{
	shash_table_t *sortedHashTbl;
	unsigned long int iterator;

	sortedHashTbl = malloc(sizeof(shash_table_t));
	if (sortedHashTbl == NULL)
		return (NULL);
	sortedHashTbl->size = tableSize;
	sortedHashTbl->shead = NULL;
	sortedHashTbl->stail = NULL;
	sortedHashTbl->array = malloc(sizeof(shash_node_t) * tableSize);
	if (sortedHashTbl->array == NULL)
	{
		free(sortedHashTbl);
		return (NULL);
	}
	for (iterator = 0; iterator < tableSize; iterator++)
	{
		sortedHashTbl->array[iterator] = NULL;
	}
	return (sortedHashTbl);
}

/**
 * Creates a node for the sorted hash table
 * @inputKey: Key for the data
 * @inputValue: Data to be stored
 *
 * Return: Pointer to the new node, or NULL if unsuccessful
 */
shash_node_t *make_shash_node(const char *inputKey, const char *inputValue)
{
	shash_node_t *sortedHashNode;

	sortedHashNode = malloc(sizeof(shash_node_t));
	if (sortedHashNode == NULL)
		return (NULL);
	sortedHashNode->key = strdup(inputKey);
	if (sortedHashNode->key == NULL)
	{
		free(sortedHashNode);
		return (NULL);
	}
	sortedHashNode->value = strdup(inputValue);
	if (sortedHashNode->value == NULL)
	{
		free(sortedHashNode->key);
		free(sortedHashNode);
		return (NULL);
	}
	sortedHashNode->next = sortedHashNode->snext = sortedHashNode->sprev = NULL;
	return (sortedHashNode);
}

/**
 * Inserts a node to the sorted linked list (sorted by key's ASCII)
 * @sortedHashTable: The sorted hash table
 * @newNode: The node to be added
 *
 * Return: void
 */
void add_to_sorted_list(shash_table_t *sortedHashTable, shash_node_t *newNode)
{
	shash_node_t *tempNode;

	if (sortedHashTable->shead == NULL && sortedHashTable->stail == NULL)
	{
		sortedHashTable->shead = sortedHashTable->stail = newNode;
		return;
	}
	tempNode = sortedHashTable->shead;
	while (tempNode != NULL)
	{
		if (strcmp(newNode->key, tempNode->key) < 0)
		{
			newNode->snext = tempNode;
			newNode->sprev = tempNode->sprev;
			tempNode->sprev = newNode;
			if (newNode->sprev != NULL)
				newNode->sprev->snext = newNode;
			else
				sortedHashTable->shead = newNode;
			return;
		}
		tempNode = tempNode->snext;
	}
	newNode->sprev = sortedHashTable->stail;
	sortedHashTable->stail->snext = newNode;
	sortedHashTable->stail = newNode;
}

/**
 * Assigns a key to a value in the hash table
 * @sortedHashTable: Sorted hash table
 * @inputKey: Key for the data
 * @inputValue: Data to be added
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(
	shash_table_t *sortedHashTable,
	const char *inputKey,
	const char *inputValue)
{
	unsigned long int hashIndex;
	char *newValue;
	shash_node_t *sortedHashNode, *tempNode;

	if (sortedHashTable == NULL || sortedHashTable->array == NULL
		|| sortedHashTable->size == 0 || inputKey == NULL
		|| strlen(inputKey) == 0 || inputValue == NULL)
		return (0);
	hashIndex =
		key_index((const unsigned char *)inputKey, sortedHashTable->size);
	tempNode = sortedHashTable->array[hashIndex];
	while (tempNode != NULL)
	{
		if (strcmp(tempNode->key, inputKey) == 0)
		{
			newValue = strdup(inputValue);
			if (newValue == NULL)
				return (0);
			free(tempNode->value);
			tempNode->value = newValue;
			return (1);
		}
		tempNode = tempNode->next;
	}
	sortedHashNode = make_shash_node(inputKey, inputValue);
	if (sortedHashNode == NULL)
		return (0);
	sortedHashNode->next = sortedHashTable->array[hashIndex];
	sortedHashTable->array[hashIndex] = sortedHashNode;
	add_to_sorted_list(sortedHashTable, sortedHashNode);
	return (1);
}

/**
 * Fetches a value from the hash table using a key
 * @sortedHashTable: Hash table
 * @inputKey: Key to the data
 *
 * Return: The value associated with key, or NULL if unsuccessful
 */
char *
shash_table_get(const shash_table_t *sortedHashTable, const char *inputKey)
{
	unsigned long int hashIndex;
	shash_node_t *tempNode;

	if (sortedHashTable == NULL || sortedHashTable->array == NULL
		|| sortedHashTable->size == 0 || inputKey == NULL
		|| strlen(inputKey) == 0)
		return (NULL);
	hashIndex =
		key_index((const unsigned char *)inputKey, sortedHashTable->size);
	tempNode = sortedHashTable->array[hashIndex];
	while (tempNode != NULL)
	{
		if (strcmp(tempNode->key, inputKey) == 0)
			return (tempNode->value);
		tempNode = tempNode->next;
	}
	return (NULL);
}

/**
 * Prints a sorted hash table
 * @sortedHashTable: Hash table to print
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *sortedHashTable)
{
	shash_node_t *tempNode;
	char printFlag = 0; /* 0 before printing any data, 1 after*/

	if (sortedHashTable == NULL || sortedHashTable->array == NULL)
		return;
	printf("{");
	tempNode = sortedHashTable->shead;
	while (tempNode != NULL)
	{
		if (printFlag == 1)
			printf(", ");
		printf("'%s': '%s'", tempNode->key, tempNode->value);
		printFlag = 1;
		tempNode = tempNode->snext;
	}
	printf("}\n");
}

/**
 * Prints a sorted hash table in reverse order
 * @sortedHashTable: Hash table to print
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *sortedHashTable)
{
	shash_node_t *tempNode;
	char printFlag = 0; /* 0 before printing any data, 1 after*/

	if (sortedHashTable == NULL || sortedHashTable->array == NULL)
		return;
	printf("{");
	tempNode = sortedHashTable->stail;
	while (tempNode != NULL)
	{
		if (printFlag == 1)
			printf(", ");
		printf("'%s': '%s'", tempNode->key, tempNode->value);
		printFlag = 1;
		tempNode = tempNode->sprev;
	}
	printf("}\n");
}

/**
 * Deletes a sorted hash table
 * @sortedHashTable: Hash table to delete
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *sortedHashTable)
{
	unsigned long int iterator;
	shash_node_t *tempNode, *nextNode;

	if (sortedHashTable == NULL || sortedHashTable->array == NULL)
		return;
	for (iterator = 0; iterator < sortedHashTable->size; iterator++)
	{
		tempNode = sortedHashTable->array[iterator];
		while (tempNode != NULL)
		{
			nextNode = tempNode->next;
			free(tempNode->key);
			free(tempNode->value);
			free(tempNode);
			tempNode = nextNode;
		}
	}
	free(sortedHashTable->array);
	free(sortedHashTable);
}
