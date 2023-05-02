/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list that were freed.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *current, *tmp;
    int diff;

    if (h == NULL || *h == NULL)
        return (count);

    current = *h;
    while (current != NULL)
    {
        diff = current - current->next;
        if (diff > 0)
        {
            tmp = current;
            current = current->next;
            free(tmp);
            count++;
        }
        else
        {
            free(current);
            count++;
            *h = NULL;
            break;
        }
    }

    return (count);
}
