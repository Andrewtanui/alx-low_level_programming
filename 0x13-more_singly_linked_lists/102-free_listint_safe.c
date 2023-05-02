/**
 * free_listint_safe - Frees a listint_t list
 * @h: Double pointer to the head of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *tmp;
	size_t count = 0;

	if (h == NULL)
		return (0);

	current = *h;

	while (current != NULL)
	{
		count++;
		if (current < current->next)
		{
			tmp = current;
			current = current->next;
			free(tmp);
		}
		else
		{
			free(current);
			*h = NULL;
			break;
		}
	}

	return (count);
}
