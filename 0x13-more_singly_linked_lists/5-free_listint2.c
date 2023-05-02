#include "lists.h"

/**
 * free_listint2 - frees a linked list but memory safe
 * @head: pointer to the listint_t list to be freed
 * Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *current_node;

	if (head == NULL)
		return;

	while (*head)
	{
		current_node = (*head)->next;
		free(*head);
		*head = current_node;
	}

	*head = NULL;
}
