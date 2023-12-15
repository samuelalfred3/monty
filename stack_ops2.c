#include "monty.h"

/**
 * stack - This sets the format of the data to a stack (LIFO)
 * @stack: The stack to manipulate (unused)
 * @count: Line number (unused)
 * Return: Nothing
 */
void stack(stack_t **stack, unsigned int count)
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
void free_stack(stack_t *stack)
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
 * stack_len - This counts stack nodes
 * @h: Double linked list head
 * Return: size of element printed
 */
size_t stack_len(const stack_t *h)
{
	const stack_t *copy = h;
	size_t _size = 0;

	while (copy)
	{
		_size++;
		copy = copy->next;
	}
	return (_size);
}
