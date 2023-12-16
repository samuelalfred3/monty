#include "monty.h"

/**
 * m_pstr - Print the values of each printable character in the stack.
 * @stack: Pointer to stack pointer
 * @count: Line number
 * Return: Nothing
 */
void m_pstr(stack_t **stack, unsigned int count)
{
	stack_t *current = *stack;
	(void)count;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
