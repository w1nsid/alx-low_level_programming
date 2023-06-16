#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at index
 * @head: head of doubly linked list
 * @index: desired index to delete node
 *
 * Return: 1 on deletion, -1 if out of range
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	current = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}
	while (current != NULL)
	{
		if (i == index)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			free(current);
			return (1);
		}
		i++;
		current = current->next;
	}
	return (-1);
}
