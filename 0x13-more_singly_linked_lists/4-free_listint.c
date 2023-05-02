#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: listint_t list to be freed
 * Return: nothing
 */
void free_listint(listint_t *head)
{
	listint_t *cur_node;

	while (head)
	{
		cur_node = head->next;
		free(head);
		head = cur_node;
	}
}
