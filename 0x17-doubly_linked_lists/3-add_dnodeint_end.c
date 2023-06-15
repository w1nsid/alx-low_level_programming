#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - add new node to end of doubly linked list
 * @head: head of doubly linked list
 * @n: value to add to new node
 *
 * Return: pointer to the new node or null if failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *current;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
	return (new);
}
