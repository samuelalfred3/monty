#include "monty.h"

/**
 * m_pchar - Print the value of the character at the top of the stack.
 * @stack: Pointer to stack pointer
 * @count: Line number
 * Return: Nothing
 */
void m_pchar(stack_t **stack, unsigned int count)
{
	stack_t *top;
	int value;

	top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: unable to pchar, stack is empty\n", count);
		fclose(data.file);
		free(data.content);
		exit(EXIT_FAILURE);
	}

	value = top->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: unable to pchar, value out of ASCII range\n", count);
		fclose(data.file);
		free(data.content);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}
