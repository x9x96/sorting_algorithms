#include "sort.h"

void node_switcher(listint_t **head, listint_t **first_node,
		listint_t *secnd_node);

/**
 * insertion_sort_list - implements the insertion sort algorithm to
 *		sort a doubly-linked list in ascending order
 * @list: head pointer
 *
 * Description: swaps nodes and updating pointers while printing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ongoing;
	listint_t *toInsert;
	listint_t *tmp_value;

	/* Checks if the list or its head is empty, or if there is only one node*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (ongoing = (*list)->next; ongoing != NULL; ongoing = tmp_value)
	{
		tmp_value = ongoing->next;

		toInsert = ongoing->prev;

		/* Move the node to its correct position in the sorted part */
		while (toInsert != NULL && ongoing->n < toInsert->n)
		{
			node_switcher(list, &toInsert, ongoing);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * node_switcher - swaps positions of two nodes in a doubly-linked list
 * @head: head pointer
 * @first_node: first node to be swapped.
 * @secnd_node: second node to be swapped.
 */
void node_switcher(listint_t **head, listint_t **first_node,
		listint_t *secnd_node)
{
	(*first_node)->next = secnd_node->next;

	/* Update the previous pointer of secnd_node's next node */
	if (secnd_node->next != NULL)
	{
		secnd_node->next->prev = *first_node;
	}

	/* Update the previous and next pointers of secnd_node */
	secnd_node->prev = (*first_node)->prev;
	secnd_node->next = *first_node;

	/* Update the next pointer of first_node's previous node */
	if ((*first_node)->prev != NULL)
	{
		(*first_node)->prev->next = secnd_node;
	}

	else
	{
		*head = secnd_node;
	}

	(*first_node)->prev = secnd_node;
	*first_node = secnd_node->prev;
}
