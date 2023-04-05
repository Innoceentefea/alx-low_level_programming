#include "lists.h"

/**
 * free_listint_safe - frees a linked list safely, even if it contains a loop
 * @h: double pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		if ((*h)->next >= *h)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			len++;
			if (temp >= *h)
				break;
		}
		else
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			len++;
		}
	}

	*h = NULL;

	return (len);
}
