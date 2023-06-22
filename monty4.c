#include "monty.h"

/**
* print_all - function that prints everything in the stack
* @head: double head pointer to the stack
* @count: unused line count
*
* Return: nothing
*/
void print_all(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
* swap_elem - function that swaps the top two elements of the stack
* @head: head of stack
* @count: line count
*
* Return: nothing
*/
void swap_elem(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
