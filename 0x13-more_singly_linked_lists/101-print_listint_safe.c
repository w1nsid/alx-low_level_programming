#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *slow_ptr, *fast_ptr;
	size_t node_count = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	/* Use Floyd's cycle-finding algorithm to detect if the list is looped */
	slow_ptr = head->next;
	fast_ptr = (head->next)->next;

	while (fast_ptr)
	{
		if (slow_ptr == fast_ptr)
		{
			/* The list is looped, so count the number of unique nodes in the loop */
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				node_count++;
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}

			/* Count the remaining nodes in the loop */
			slow_ptr = slow_ptr->next;
			while (slow_ptr != fast_ptr)
			{
				node_count++;
				slow_ptr = slow_ptr->next;
			}

			return (node_count);
		}

		/* Move the pointers through the list */
		slow_ptr = slow_ptr->next;
		fast_ptr = (fast_ptr->next)->next;
	}

	/* The list is not looped, so return 0 */
	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count, index = 0;

	node_count = looped_listint_len(head);

	if (node_count == 0)
	{
		/* The list is not looped, so print all nodes in the list */
		for (; head != NULL; node_count++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < node_count; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (node_count);
}
