#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head of the linked list.
 * @index: Index of the node to return.
 *
 * Return: If the node exists, return a pointer to the node.
 *         Otherwise, return NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int count = 0;
    listint_t *current = head;

    while (current != NULL)
    {
        if (count == index)
            return (current);
        count++;
        current = current->next;
    }

    return (NULL);
}
