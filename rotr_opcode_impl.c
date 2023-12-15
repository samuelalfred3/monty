#include "monty.h"

/**
 * rotr - This rotates the stack to the bottom
 * @stack: stack to manipulate
 * @count: Line number (unused parameter)
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int count)
{
	stack_t *temp;
	int n;
	(void)count;

	if (!(*stack) || stack_len(*stack) == 1)
		return;

	while ((*stack)->next->next)
		(*stack) = (*stack)->next;

	n = (*stack)->next->n;
	temp = (*stack)->next;
	(*stack)->next = NULL;

	while ((*stack)->prev)
		(*stack) = (*stack)->prev;

	add_node(stack, n);
	free(temp);
}
