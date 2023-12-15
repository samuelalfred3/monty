#include "monty.h"

/**
 * div - is a function that divides top two elements of the stack.
 * @stack: data structure to manipulate.
 * @count: line we are reading from in the file.
 *
 * Return: Nothing
 */
void div(stack_t **stack, unsigned int count)
{
	stack_t *p;
	int size = 0;
	int divisor, quotient;

	p = *stack;
	while (p)
	{
		p = p->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(data.file);
		free(data.content);
		exit(EXIT_FAILURE);
	}
	p = *stack;
	if (p->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(data.file);
		free(data.content);
		exit(EXIT_FAILURE);
	}
	divisor = p->n;
	quotient = p->next->n / divisor;
	p->next->n = quotient;
	*stack = p->next;
	free(p);
}
