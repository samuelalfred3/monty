#include "monty.h"

/**
 * m_swap - a function that swaps the top two elements of the stack
 * @stack: the data structures to manipulate.
 * @count: the line number in the file
 *
 * Return: Nothing
 */
void m_swap(stack_t **stack, unsigned int count)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: stack too short, can't swap\n", count);
		exit(EXIT_FAILURE);
	}
	stack_t *top = *stack;
	stack_t *nextNode = top->next;

	top->next = nextNode->next;
	if (nextNode->next != NULL)
		nextNode->next->prev = top;

	nextNode->next = top;
	nextNode->prev = NULL;
	top->prev = nextNode;
	*stack = nextNode;
}
