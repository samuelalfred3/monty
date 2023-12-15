#include "monty.h"

/**
 * rotl - This rotates the stack to the top
 * @stack: The stack to manipulate
 * @count: The Line number
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int count)
{
	stack_t *tmp;
	int n;
	(void)count;

	if (!(*stack) || stack_len(*stack) == 1)
		return;

	n = (*stack)->n;
	tmp = *stack;
	(*stack) = (*stack)->next;
	add_node_end(stack, n);
	free(tmp);
}
