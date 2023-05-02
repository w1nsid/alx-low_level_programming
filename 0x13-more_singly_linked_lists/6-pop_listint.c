#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a
 * listint_t linked list,
 * and returns the head node’s data (n).
 * @head: pointer to the first element in the linked list
 *
 * Return: the head node’s data (n) or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *current_node;
	int node_count;

	if (!head || !*head)
		return (0);

	node_count = (*head)->n;
	current_node = (*head)->next;
	free(*head);
	*head = current_node;

	return (node_count);
}
