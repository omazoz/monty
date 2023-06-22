#include "monty.h"

/**
 * add_to_stack - function that adds the top two elements of the stack
 * @head: double pointer head to the stack
 * @count: line count
 *
 * Return: nothing
 */
void add_to_stack(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp = h->n + h->next->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}

/**
 * substract - function that substracts nodes
 * @head: double head pointer to the stack
 * @count: line count
 *
 * Return: nothing
 */
void substract(stack_t **head, unsigned int count)
{
	stack_t *tmp;
	int sub, node;

	tmp = *head;
	for (node = 0; tmp != NULL; node++)
		tmp = tmp->next;
	if (node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sub = tmp->next->n - tmp->n;
	tmp->next->n = sub;
	*head = tmp->next;
	free(tmp);
}

/**
 * multiply - function that multiplies the top two elements of the stack
 * @head: double head pointer to the stack
 * @count: line count
 *
 * Return: nothing
 */
void multiply(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp = h->next->n * h->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}

/**
 * div - function that divides the top two elements of the stack
 * @head: double head pointer to the stack
 * @count: line count
 *
 * Return: nothing
 */
void div(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = h->next->n / h->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}

/**
 * remain - function that computes the remainder of the division of the second
 * top element of the stack by the top element of the stack
 * @head: double head pointer to the stack
 * @count: line count
 *
 * Return: nothing
 */
void remain(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = h->next->n % h->n;
	h->next->n = tmp;
	*head = h->next;
	free(h);
}
