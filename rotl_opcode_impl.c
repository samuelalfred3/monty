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

	if (!(*stack) || get_stack_size(*stack) == 1)
		return;

	value = (*stack)->n;
	temp = *stack;
	(*stack) = (*stack)->next;
	push_start(stack, value);
	free(temp);
}
