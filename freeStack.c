#include "monty.h"

/**
 * free_stack - function that frees a doubly linked list
 * @head: head pointer to the stack
 *
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
