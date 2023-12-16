#include "monty.h"

/**
 * m_sub - a func that subtracts the top element from the second top element.
 * @stack: the data structure to manipulate.
 * @count: the line we are reading from in the file.
 *
 * Return: Nothing
 */
void m_sub(stack_t **stack, unsigned int count)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: Unable to perform sub, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	int result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;

	stack_t *temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
