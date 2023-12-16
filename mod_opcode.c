#include "monty.h"

/**
 * m_mod - This calculates the modulo of the two top stack elements
 * @stack: Is pointer to stack pointer
 * @count: Th line number
 * Return: Nothing
 */
void m_mod(stack_t **stack, unsigned int count)
{
	stack_t *copy;
	int val, size = stack_len(*stack);

	copy = *stack;
	if (size < 2)
	{
		fprintf(stderr, "L%d: cannot perform mod, stack too short\n", count);
		fclose(data.file);
		free(data.content);
		exit(EXIT_FAILURE);
	}
	if (copy->n == 0)
	{
		fprintf(stderr, "L%d: cannot divide by zero\n", count);
		fclose(data.file);
		free(data.content);
		exit(EXIT_FAILURE);
	}
	val = copy->next->n % copy->n;
	copy->next->n = val;
	*stack = copy->next;
	free(copy);
}
