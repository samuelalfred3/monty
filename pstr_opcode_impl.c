#include "monty.h"

/**
 * pstr - This prints the values of each character number
 * @stack: The pointer to stack pointer
 * @count: The line number
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int count)
{
	stack_t *p;
	(void)count;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}

	p = *stack;
	while (p != NULL)
	{
		if (p->n <= 0 || p->n > 127)
		{
			break;
		}
		printf("%c", p->n);
		p = p->next;
	}

	putchar('\n');
}
