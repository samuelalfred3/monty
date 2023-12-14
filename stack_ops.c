#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: value to push to the stack
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n;

	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (global.argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", global.line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(global.argument);
	if (n == 0 && strcmp(global.argument, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", global.line_number);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all values on the stack
 * @stack: double pointer to top of stack
 * @line_number: line number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
