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

/**
 * print_top - function that prints the top
 * @head: head of stack
 * @count: line count
 *
 * Return: nothing
 */
void print_top(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 0;
}
