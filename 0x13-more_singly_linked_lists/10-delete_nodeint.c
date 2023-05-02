#include "lists.h"

/**
 * delete_node_at_index - Deletes a node from a linked list at a given index.
 * @head: A pointer to the head of the linked list.
 * @index: The index of the node to be deleted.
 *
 * Return: 1 if the operation was successful, or -1 if it failed.
 */
int delete_node_at_index(listint_t **head, unsigned int index)
{
	listint_t *current_node = *head;
	listint_t *previous_node = NULL;
	unsigned int node_count = 0;

	/* Check if the head of the linked list is NULL */
	if (*head == NULL)
		return (-1);

	/* If the index is 0, delete the head of the linked list */
	if (index == 0)
	{
		*head = (*head)->next;
		free(current_node);
		return (1);
	}

	/* Traverse the linked list until the node before the index */
	while (node_count < index - 1)
	{
		if (!current_node || !(current_node->next))
			return (-1);

		current_node = current_node->next;
		node_count++;
	}

	/* Delete the node at the given index */
	previous_node = current_node;
	current_node = current_node->next;
	previous_node->next = current_node->next;
	free(current_node);

	return (1);
}
