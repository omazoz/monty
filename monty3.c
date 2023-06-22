#include "monty.h"
#include <string.h>
/**
*push - add a neode in the list
*@stack: pointer to a pointer to the doubly linked list
*@counter: line where there is an error
*Return: nothing
*/
void push(stack_t **stack, char *n, unsigned int counter)
{
	stack_t *new = NULL;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}
	for (i = 0; n[i]; i++)
	{
		if (n[0] == '-' && i == 0)
			continue;
		if (n[i] < 48 || n[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			exit(EXIT_FAILURE);
		}
	}
	new->n = atoi(n);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
* swap - swaps the value of the top two elements to the stack
* @stack: pointer that point to stack
* @counter: line number of instruction
* Return: void, exit with -1 on failure
**/
void swap(stack_t **stack, unsigned int counter)
{
	int i;

	if (len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = i;
}

