#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a linked list
 * @head: pointer to the head of the list
 * @n: integer value to store in the new node
 * Return: pointer to the new node, or NULL on failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	/* allocate memory for the new node */
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	/* initialize the new node */
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL) /* the list is empty */
		*head = new_node;
	else
	{
		/* traverse the list until the last node */
		listint_t *last_node = *head;

		while (last_node->next != NULL)
			last_node = last_node->next;

		/* append the new node to the end */
		last_node->next = new_node;
	}

	return (new_node);
}
