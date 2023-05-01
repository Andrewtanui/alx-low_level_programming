#include "lists.h"
#include <stdio.h>

/**
 * pop_listint - Deletes the head node of a linked list and returns its data.
 *
 * @head: A pointer to a pointer to the first node of the linked list.
 *
 * Return: The data stored in the head node, or 0 if the linked list is empty.
 */
int pop_listint(listint_t **head)
{
    int data;
    listint_t *temp;

    if (*head == NULL)
        return (0);

    temp = *head;
    data = temp->n;
    *head = (*head)->next;
    free(temp);

    return (data);
}
