#include "sort.h"

void cocktail_sort_list(listint_t **list);
void forward_swap(listint_t **list, listint_t **toTail, listint_t **toNode);
void backwards_swap(listint_t **list, listint_t **toTail, listint_t **toNode);


/**
 * cocktail_sort_list - implements the cocktail sort algorithm to sort a
 *		doubly-linked list in ascending order
 * @list: head pointer
 *
 * Description: swaps nodes and updating pointers while printing
 */
void cocktail_sort_list(listint_t **list)
{
	bool checkSorted = false;
	listint_t *toTail;
	listint_t *toNode;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (toTail = *list; toTail->next != NULL;)
	{
		toTail = toTail->next;
	}
	while (checkSorted == false)
	{
		checkSorted = true;
		for (toNode = *list; toNode != toTail; toNode = toNode->next)
		{
			if (toNode->n > toNode->next->n)
			{
				forward_swap(list, &toTail, &toNode);
				print_list((const listint_t *)*list);
				checkSorted = false;
			}
		}
		for (toNode = toNode->prev; toNode != *list;
				toNode = toNode->prev)
		{
			if (toNode->n < toNode->prev->n)
			{
				backwards_swap(list, &toTail, &toNode);
				print_list((const listint_t *)*list);
				checkSorted = false;
			}
		}
	}
}


/**
 * forward_swap - swaps a node forward in a doubly-linked list
 * @list: head pointer
 * @toTail: tail pointer
 * @toNode: current node of the cocktail shaker algo
 */
void forward_swap(listint_t **list, listint_t **toTail, listint_t **toNode)
{
	listint_t *temp_val;

	temp_val = (*toNode)->next;

	if ((*toNode)->prev != NULL)
	{
		(*toNode)->prev->next = temp_val;
	}

	else
	{
		*list = temp_val;
	}

	temp_val->prev = (*toNode)->prev;
	(*toNode)->next = temp_val->next;

	if (temp_val->next != NULL)
	{
		temp_val->next->prev = *toNode;
	}

	else
	{
		*toTail = *toNode;
	}

	(*toNode)->prev = temp_val;
	temp_val->next = *toNode;
	*toNode = temp_val;
}

/**
 * backwards_swap - swaps a node backwards in a doubly-linked list
 * @list: head pointer
 * @toTail: tail pointer
 * @toNode: current node of the cocktail shaker algo
 */
void backwards_swap(listint_t **list, listint_t **toTail, listint_t **toNode)
{
	listint_t *temp_val;

	temp_val = (*toNode)->prev;

	if ((*toNode)->next != NULL)
	{
		(*toNode)->next->prev = temp_val;
	}

	else
	{
		*toTail = temp_val;
	}
	temp_val->next = (*toNode)->next;
	(*toNode)->prev = temp_val->prev;

	if (temp_val->prev != NULL)
	{
		temp_val->prev->next = *toNode;
	}

	else
	{
		*list = *toNode;
	}

	(*toNode)->next = temp_val;
	temp_val->prev = *toNode;
	*toNode = temp_val;
}

