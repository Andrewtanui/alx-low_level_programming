#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - Frees a listint_t list.
 *
 * @head: A pointer to the first node in the listint_t list.
 *
 * Return: void.
 */
void free_listint(listint_t *head)
{
	listint_t *current_node, *next_node;

	current_node = head;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
