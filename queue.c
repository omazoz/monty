#include "monty.h"

/**
 * print_top - function that prints the top of the queue
 * @head: head of queue
 * @count: line count
 *
 * Return: nothing
 */
void print_top(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}

/**
 * add_queue - function that add node to the tail the queue
 * @n: new value
 * @head: head of the queue
 *
 * Return: nothing
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}
