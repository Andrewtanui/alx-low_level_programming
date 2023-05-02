#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * free_listint_safe - Frees a listint_t list safely (ie.
 *                     can free lists containing loops)
 * @h: A pointer to the address of the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t size = 0;
    listint_t *slow = *h, *fast = *h, *tmp;

    if (!h || !*h)
        return (size);

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            size = count_nodes(*h, slow);
            free_nodes(h, slow);
            break;
        }
    }

    if (!size)
        free_nodes(h, NULL);

    return (size);
}

/**
 * count_nodes - Counts the number of nodes in a looped listint_t linked list.
 * @h: A pointer to the head of the listint_t to check.
 * @loop: A pointer to the node where the loop was detected.
 *
 * Return: The number of nodes in the loop.
 */
size_t count_nodes(listint_t *h, listint_t *loop)
{
    size_t count = 1;
    listint_t *tmp = loop;

    while (tmp->next != loop)
    {
        count++;
        tmp = tmp->next;
    }

    tmp = h;

    while (tmp != loop)
    {
        count++;
        tmp = tmp->next;
    }

    return (count);
}

/**
 * free_nodes - Frees the nodes of a listint_t list.
 * @h: A pointer to the address of the head of the listint_t list.
 * @loop: A pointer to the node where the loop was detected.
 */
void free_nodes(listint_t **h, listint_t *loop)
{
    listint_t *tmp = *h;

    while (tmp && tmp != loop)
    {
        *h = (*h)->next;
        free(tmp);
        tmp = *h;
    }

    if (loop)
    {
        listint_t *prev = loop;

        while (prev->next != loop)
            prev = prev->next;

        prev->next = NULL;
        free(loop);
    }

    *h = NULL;
}
