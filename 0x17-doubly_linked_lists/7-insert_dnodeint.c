#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_dnodeint_at_index - adds a new node at index
 * @h: head of the linked list
 * @idx: desired index to add node
 * @n: desired value of node
 *
 * Return: new node or NULL if fail
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *current;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	current = *h;
	while (current != NULL)
	{
		if (i == idx - 1)
		{
			new->prev = current;
			new->next = current->next;
			if (current->next != NULL)
				current->next->prev = new;
			current->next = new;
			return (new);
		}
		i++;
		current = current->next;
	}
	free(new);
	return (NULL);
}
