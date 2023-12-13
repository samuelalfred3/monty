#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: value of the new element
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i;
	char *arg;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || _isdigit(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = atoi(arg);
	if (!add_node(stack, i))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints all values on the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void) line_number;

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
