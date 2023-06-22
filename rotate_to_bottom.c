#include "monty.h"

/**
* rotate_to_bot - function that rotates the stack to the bottom
* @head: stack head of the stack
* @count: line count
*
* Return: nothing
*/
void rotate_to_bot(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
