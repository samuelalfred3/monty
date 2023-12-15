#include "monty.h"

/**
 * pchar - This prints the value of the character number
 * @stack: The pointer to stack pointer
 * @count: The line number
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int count)
{
	stack_t *p;

	p = *stack;
	if (p == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(data.file);
		free(data.content);
		exit(EXIT_FAILURE);
	}
	if (p->n < 0 || p->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(data.file);
		free(data.content);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", p->n);
}
