#include "monty.h"

/**
 * pint - a function that print the value of the first node
 * @stack: the stack to manipulate
 * @count: the line we are reading from in the file.
 * Return: void
 */
void pint(stack_t **stack, unsigned int count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
