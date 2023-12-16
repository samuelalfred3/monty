#include "monty.h"

/**
 * push_start - Add a node to the stack (can be used for both stack and queue)
 * @stack: the stack to manipulate
 * @n: Node value
 * Return: Nothing
 */
void push_start(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * push_end - Add new node to the end of a doubly linked list
 * @stack: stack to manipulate
 * @n: Node value
 * Return: Nothing
 */
void push_end(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;

	if (*stack)
	{
		new->prev = NULL;
		(*stack) = new;
	}
	else
	{
		stack_t *prev_node = *stack;

		while (prev_node->next)
			prev_node = prev_node->next;

		prev_node->next = new;
		new->prev = prev_node;
	}
}
