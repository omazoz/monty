#include "monty.h"

/**
* pop_func - function that prints the top of the stack
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void pop_func(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
* print - function that prints the top of the stack
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void print(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* noth - function that does nothing
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void noth(stack_t **head, unsigned int count)
{
	(void) count;
	(void) head;
}
