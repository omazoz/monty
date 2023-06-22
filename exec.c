#include "monty.h"

/**
* execute - function that executes the opcode
* @stack: head stack linked list
* @count: line count
* @file: pointer to monty file stream
* @content: line content
*
* Return: nothing
*/
int execute(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
		{"push", add_node}, {"pall", print_all}, {"pint", print},
		{"pop", pop_func}, {"swap", swap_elem}, {"add", add_to_stack},
		{"nop", noth}, {"sub", substract}, {"div", div},
		{"mul", multiply}, {"mod", remain}, {"pchar", print_char},
		{"pstr", print_string}, {"rotl", rotate_to_top}, {"rotr", rotate_to_bot},
		{"queue", print_top}, {"stack", print_top},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return 0;

	bus.arg = strtok(NULL, " \n\t");

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, count);
			return 0;
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return 1;
}
