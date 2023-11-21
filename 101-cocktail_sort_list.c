#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start, *end;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do
	{
		swapped = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
				print_list(*list);
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		for (end = start; start->prev != NULL; start = start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
