#include "lists.h"

/**
 * looped_listint_count - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_count(listint_t *head)
{
    listint_t *slow = head, *fast = head;
    int flag = 0;
    size_t count = 0;

    if (!head)
        return (0);

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            flag = 1;
            break;
        }
    }

    if (!flag)
        return (0);

    do {
        slow = slow->next;
        count++;
    } while (slow != fast);

    return (count);
}

/**
 * free_listint_safe - Frees a listint_t list safely (ie.
 *                     can free lists containing loops)
 * @h: A pointer to the address of
 *     the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *current, *tmp;
    int loop_detected = 0;

    if (h == NULL || *h == NULL)
        return (count);

    current = *h;

    while (current != NULL)
    {
        if (current->next >= current)
        {
            loop_detected = 1;
            break;
        }

        tmp = current->next;
        free(current);
        current = tmp;
        count++;
    }

    if (loop_detected)
    {
        *h = NULL;
        return (count);
    }

    *h = NULL;
    return (count);
}
