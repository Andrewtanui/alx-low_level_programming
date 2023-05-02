#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: A pointer to a pointer to the head node of the list
 * @idx: The index of the list where the new node should be added
 * @n: The data to be stored in the new node
 *
 * Return: The address of the new node, or NULL if it failed
 **/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *tmp;
    unsigned int i;

    if (head == NULL)
        return (NULL);

    /* Special case for idx == 0 */
    if (idx == 0)
        return (add_nodeint(head, n));

    /* Traverse the list until the node before the desired index */
    tmp = *head;
    for (i = 0; i < idx - 1; i++)
    {
        if (tmp == NULL)
            return (NULL);
        tmp = tmp->next;
    }

    /* Check if we reached the end of the list */
    if (tmp == NULL)
        return (NULL);

    /* Create the new node and link it to the list */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = n;
    new_node->next = tmp->next;
    tmp->next = new_node;

    return (new_node);
}
