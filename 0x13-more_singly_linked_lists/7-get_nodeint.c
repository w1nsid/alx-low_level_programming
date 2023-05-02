#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a certain index in a linked list
 * @current_node: first node in the linked list
 * @index: index of the node to return
 *
 * Return: pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *current_node, unsigned int index)
{
	unsigned int current_index = 0;
	listint_t *temp = current_node;

	while (temp && current_index < index)
	{
		temp = temp->next;
		current_index++;
	}

	return (temp ? temp : NULL);
}
