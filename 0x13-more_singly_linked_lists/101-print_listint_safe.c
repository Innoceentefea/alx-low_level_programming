#include "lists.h"

/**
 * print_listint_safe - prints a linked list safely
 * @head: pointer to the first node in the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current_node = NULL;
	const listint_t *node_to_check = NULL;
	size_t node_count = 0;
	size_t nodes_checked;

	current_node = head;
	while (current_node)
	{
		printf("[%p] %d\n", (void *)current_node, current_node->n);
		node_count++;
		current_node = current_node->next;
		node_to_check = head;
		nodes_checked = 0;
		while (nodes_checked < node_count)
		{
			if (current_node == node_to_check)
			{
				printf("-> [%p] %d\n", (void *)current_node, current_node->n);
				return (node_count);
			}
			node_to_check = node_to_check->next;
			nodes_checked++;
		}
		if (!head)
			exit(98);
	}
	return (node_count);
}
