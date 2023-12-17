#include "monty.h"

/**
 * m_add - a function that adds the top two elements of the stack.
 * @stack: the data structures to manipulate.
 * @count: the line we are reading from in the file.
 *
 * Return: Nothing
 */
void m_add(stack_t **stack, unsigned int count)
{
	int sum;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: addition not possible\n", count);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
