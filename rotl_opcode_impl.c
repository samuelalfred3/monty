#include "monty.h"

/**
 * m_rotl - This rotates the stack to the top
 * @stack: Pointer to stack pointer
 * @count: The Line number
 * Return: Nothing
 */
void m_rotl(stack_t **stack, unsigned int count)
{
	stack_t *temp;
	int value;
	(void)count;

	if (!(*stack) || stack_len(*stack) == 1)
		return;

	value = (*stack)->n;
	temp = *stack;
	(*stack) = (*stack)->next;
	add_node_end(stack, n);
	free(tmp);
}
