#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 * @index: The index of the node to return.
 *
 * Return: If the node does not exist - NULL.
 *         Otherwise - a pointer to the requested node.
 **/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;

    for (i = 0; head && i < index; i++)
        head = head->next;

    return (i == index ? head : NULL);
}
