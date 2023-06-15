#include "lists.h"

/**
 * dlistint_len - return the number of elements in a linked dlistint_t list
 * @h: head of the linked list
 *
 * Return: number of elements in the linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		h = h->next;
		i++;
	}
	return (i);
}
