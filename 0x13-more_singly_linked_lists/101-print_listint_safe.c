#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *curr = head, *prev = NULL;
	size_t count = 0;

	if (head == NULL)
		exit(98);

	while (curr != NULL)
	{
		count++;
		printf("[%p] %d\n", (void *)curr, curr->n);

		if (curr < prev)
		{
			printf("-> [%p] %d\n", (void *)prev, prev->n);
			break;
		}

		prev = curr;
		curr = curr->next;
	}

	return (count);
}
