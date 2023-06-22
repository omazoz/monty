#include "monty.h"
/**
 *pop - removes the last inserted element
 *@counter: number of lines  in the file
 *@stack: pointer to the pointer to the head
 *Return: nothing
 */
void pop(stack_t **stack, unsigned int counter)
{
stack_t *end;
if (stack == NULL)
{
printf("L%u: can't pop an empty stack\n", counter);
exit(EXIT_FAILURE);
}
else if (*stack == NULL)
{
printf("L%u: can't pop an empty stack\n", counter);
exit(EXIT_FAILURE);
}
else
{
end = *stack;
*stack = (*stack)->next;
free(end);
}
return;
}

#include "monty.h"
/**
*pint - print the data at the top
*@stack: double pointer th the head
*@counter: number of lines
*Return: nothing
*/
void pint(stack_t **stack, unsigned int __attribute__((unused)) counter)
{
if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}	