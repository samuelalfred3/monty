#include "monty.h"

/**
 * m_mul - is a function that multiplies the top two elements of the stack.
 * @stack: data structure to manipulate.
 * @count: line we are reading from in the file.
 *
 * Return: Nothing
 */
void m_mul(stack_t **stack, unsigned int count)
{
	stack_t *p;
	int val;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(data.file);
		free(data.content);
		exit(EXIT_FAILURE);
	}
	p = *stack;
	val = p->n * p->next->n;
	p->next->n = val;
	*stack = p->next;
	free(p);
}
