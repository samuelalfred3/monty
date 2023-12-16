#include "monty.h"

/**
 * m_pop - is a function that remove the first node in a list
 * @stack: data structures to manipulate.
 * @count: line we are reading from in the file.
 *
 * Return: Nothing
 */
void m_pop(stack_t **stack, unsigned int count)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: unable to pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = (*stack)->next;

	if (data.file != NULL)
		fclose(data.file);
	free(data.content);
	free(top);
}
