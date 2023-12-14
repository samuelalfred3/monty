#include "monty.h"

/**
 * free_stack - frees a stack_t stack
 * @stack: stack to be freed
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
