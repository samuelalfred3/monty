#include "monty.h"

/**
 * pop - is a function that remove the first node in a list
 * @stack: data structures to manipulate.
 * @count: line we are reading from in the file.
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int count)
{
	stack_t *p;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}
	p = *stack;
	*stack = (*stack)->next;

	if (data.file != NULL)
		fclose(data.file);
	free(data.content);
	free(p);
}
