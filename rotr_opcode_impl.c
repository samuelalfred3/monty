#include "monty.h"

/**
 * m_rotr - This rotates the stack to the bottom
 * @stack: stack to manipulate
 * @count: Line number (unused parameter)
 * Return: Nothing
 */
void m_rotr(stack_t **stack, unsigned int count)
{
	stack_t *temp;
	int value;
	(void)count;

	if (!(*stack) || get_stack_size(*stack) == 1)
		return;

	while ((*stack)->next->next)
		(*stack) = (*stack)->next;

	value = (*stack)->next->n;
	temp = (*stack)->next;
	(*stack)->next = NULL;

	while ((*stack)->prev)
		(*stack) = (*stack)->prev;

	push_start(stack, value);
	free(temp);
}
