#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers,
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: the list
 * Return: void
**/

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp, *next, *next_temp, *prev_temp;
	int i = 0;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = *list;
	node = node->next;
	while (node != NULL)
	{
		temp = node;
		next = node->next;
		next_temp = temp->next;
		prev_temp = temp->prev;

		while (temp->prev != NULL && prev_temp->n > temp->n)
		{
			if (next_temp != NULL)
				next_temp->prev = prev_temp;
			prev_temp->next = next_temp;
			if (prev_temp->prev == NULL)
			{
				prev_temp->prev = temp;
				*list = temp;
				temp->prev = NULL;
			}
			else
			{
				temp->prev = prev_temp->prev;
				prev_temp->prev->next = temp;
				prev_temp->prev = temp;
			}
			temp->next = prev_temp;
			prev_temp = temp->prev;
			next_temp = temp->next;
			print_list(*list);
		}
		node = next;
		i++;
	}
}
