#include "sort.h"

/**
 * swap_nodes - İki düyünün yerini ikili əlaqəli siyahıda dəyişir
 * @list: Siyahının başına olan pointer
 * @node1: Birinci düyün
 * @node2: İkinci düyün (node1-dən sonra gələn)
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node2->prev = node1->prev;
	node1->next = node2->next;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list - Doubly linked list-i insertion sort ilə sıralayır
 * @list: Siyahının başına olan pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list(*list);
		}
	}
}
