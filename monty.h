#ifndef TADEM_H
#define TADEM_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;


/**
* struct bus_s - variables -args, file, line content
* @arg: value
* @file: pointer to monty file
* @content: line content
* @lifi: flag change stack <-> queue
*
* Description: carries values through the program
*/
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

/*functions*/
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void add_node(stack_t **head, unsigned int num);
void print_all(stack_t **head, unsigned int num);
void print(stack_t **head, unsigned int num);
int execute(char *content, stack_t **head, unsigned int count, FILE *file);
void free_stack(stack_t *head);
void pop_func(stack_t **head, unsigned int count);
void swap_elem(stack_t **head, unsigned int count);
void add_to_stack(stack_t **head, unsigned int count);
void noth(stack_t **head, unsigned int count);
void substract(stack_t **head, unsigned int count);
void my_div(stack_t **head, unsigned int count);
void multiply(stack_t **head, unsigned int count);
void remain(stack_t **head, unsigned int count);
void print_char(stack_t **head, unsigned int count);
void print_string(stack_t **head, unsigned int count);
void rotate_to_top(stack_t **head, unsigned int count);
void rotate_to_bot(stack_t **head, __attribute__((unused)) unsigned int count);
void f_push(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void print_top(stack_t **head, unsigned int count);
void print_top(stack_t **head, unsigned int count);


#endif
