#include "monty.h"

/**
 * _push - a function that adds a node to a list
 * @stack: the data structures to manipulate.
 * @count: the line we are reading from in the file.
 *
 * Return: NONE
 */
void _push(stack_t **stack, unsigned int count)
{
	int n;
	(void)count;

	if (data.token == NULL || !is_number(data.token))
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(data.token);
	if (data.mode == 0)
		add_node(stack, n);
	else
	{
		if (stack_len(*stack) == 0)
			add_node(stack, n);
		else
			add_node_end(stack, n);
	}
}

/**
 * _pall - prints all values on the stack
 * @stack: the stack to manipulate
 * @count: the line we are reading from in the file.
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int count)
{
	(void)count;
	stack_t *m;

	m = *stack;
	while (m != NULL)
	{
		printf("%d\n", m->n);
		m = m->next;
	}
	free_stack(*stack);
}
