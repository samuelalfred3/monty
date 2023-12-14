#include "monty.h"

/**
 * swap - a function that swaps the top two elements of the stack
 * @stack: the data structures to manipulate.
 * @count: the line number in the file
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int count)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
