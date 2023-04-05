#include "lists.h"

/**
 * free_listint - frees a linked list of integers
 * @head: a pointer to the head of the list
 *
 * This function traverses the list starting from the head,
 * freeing each node as it goes along.
 */
void free_listint(listint_t *head)
{
	listint_t *current = head;

	while (current != NULL)
	{
		listint_t *temp = current;

		current = current->next;

		free(temp);
	}
}
