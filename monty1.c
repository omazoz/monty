#include "monty.h"

/**
* len - length of stack
* @stack: pointer that point to stack
* Return: unsigned int
**/
unsigned int len(stack_t **stack)
{
stack_t *curr;
unsigned int l = 0;

curr = *stack;
while (curr)
{
curr = curr->next;
l++;
}
return (l);
}

/**
*pall - function to print stack's elements
*@counter: will not be used , we usse attribute not void
*@stack: pointer to the head of the doubly linked list
*Return: Nothing
*/

void pall(stack_t **stack, unsigned int __attribute__((unused)) counter)
{
stack_t *curr = *stack;

if (stack == NULL || *stack == NULL)
return;

while (curr != NULL)
{
printf("%d\n", curr->n);
curr = curr->next;
}
}
