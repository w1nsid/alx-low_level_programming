#include "lists.h"

/**
 * reverse_listint - Reverses a singly linked list in place.
 * @head: Pointer to a pointer to the head of the linked list.
 *
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous_node = NULL; /* Pointer to the previous node */
	listint_t *current_node = *head; /* Pointer to the current node */
	listint_t *next_node = NULL;	 /* Pointer to the next node */

	while (current_node != NULL)
	{
		next_node = current_node->next;
		current_node->next = previous_node;
		previous_node = current_node;
		current_node = next_node;
	}

	*head = previous_node;

	return (*head);
}
