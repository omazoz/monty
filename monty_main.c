#include "monty.h"
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>


bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - function for monty code interpreter
* @argc: argument count
* @argv: argument value
*
* Return: 0 on success
*/


#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    char content[MAX_LINE_LENGTH];
    FILE *file;
    stack_t *stack = NULL;
    unsigned int count = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (fgets(content, MAX_LINE_LENGTH, file) != NULL)
    {
        count++;
        execute(content, &stack, count, file);
    }
    free_stack(stack);
    fclose(file);
    return (0);
}