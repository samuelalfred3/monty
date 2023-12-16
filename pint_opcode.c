#include "monty.h"

/**
 * m_pint - Print the value of the first node in the stack.
 * @stack: Pointer to stack pointer
 * @count: Line number
 * Return: void
 */
void m_pint(stack_t **stack, unsigned int count)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%u: unable to pint, stack is empty\n", count);
		fclose(data.file);
		free(data.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
