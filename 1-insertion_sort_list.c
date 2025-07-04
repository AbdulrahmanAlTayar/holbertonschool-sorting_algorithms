#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending
*                       order using the Insertion sort algorithm
* @list: Double pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev_node;

if (!list || !*list || !(*list)->next)
return;

current = (*list)->next;

while (current)
{
prev_node = current->prev;

while (prev_node && prev_node->n > current->n)
{
if (current->next)
current->next->prev = current->prev;
current->prev->next = current->next;

current->prev = prev_node->prev;
current->next = prev_node;

if (prev_node->prev)
prev_node->prev->next = current;
else
*list = current;

prev_node->prev = current;

print_list(*list);
prev_node = current->prev;
}

current = current->next;
}
}
