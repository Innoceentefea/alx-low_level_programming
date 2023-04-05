#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *new_head = NULL;

	while (*head)
	{
		listint_t *next = (*head)->next;
		(*head)->next = new_head;
		new_head = *head;
		*head = next;
	}

	return (new_head);
}
