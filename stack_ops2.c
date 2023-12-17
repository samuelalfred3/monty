#include "monty.h"

/**
 * m_stack - This sets the format of the data to a stack (LIFO)
 * @stack: The stack to manipulate (unused)
 * @count: Line number (unused)
 * Return: Nothing
 */
void m_stack(stack_t **stack, unsigned int count)
{
	(void)stack;
	(void)count;
	data.mode = STACK_MODE;
}

/**
 * free_stack - This Frees a stack
 * @stack: Double linked list stack
 * Return: Nothing
 */
void free_my_stack(stack_t *stack)
{
	stack_t *next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

/**
 * get_stack_size - This counts stack nodes
 * @h: Double linked list head
 * Return: size of the stack
 */
size_t get_stack_size(const stack_t *h)
{
	const stack_t *current = h;
	size_t stack_size = 0;

	while (current)
	{
		stack_size++;
		current = current->next;
	}
	return (stack_size);
}
