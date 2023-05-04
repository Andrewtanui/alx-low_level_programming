#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *first, *rest;

	if (*head == NULL || (*head)->next == NULL)
		return (*head);

	first = *head;
	rest = first->next;

	/* Recursively reverse the rest of the list */
	reverse_listint(&rest);

	/* Fix the head pointer */
	first->next->next = first;
	first->next = NULL;
	*head = rest;

	return (*head);
}
