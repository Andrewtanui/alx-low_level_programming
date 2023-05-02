#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list safely (handles loops)
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	const listint_t *prev;

	while (current != NULL)
	{
		count++;
		printf("[%p] %d\n", (void *) current, current->n);
		prev = current;
		current = current->next;
		if (current >= prev)
		{
			printf("-> [%p] %d\n", (void *) current, current->n);
			exit(98);
		}
	}
	return (count);
}
