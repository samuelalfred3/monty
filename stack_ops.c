#include "monty.h"

/**
 * m_push - Add a node to the stack.
 * @stack: Pointer to stack pointer.
 * @count: Line number
 *
 * Return: Nothing
 */
void m_push(stack_t **stack, unsigned int count)
{
	int value;
	(void)count;

	if (data.token == NULL || !is_number(data.token))
	{
		fprintf(stderr, "L%d: invalid usage of push, provide an integer\n", count);
		fclose(data.file);
		free(data.content);
		free_my_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(data.token);
	if (data.mode == 0)
		push_start(stack, value);
	else
	{
		if (get_stack_size(*stack) == 0)
			push_start(stack, value);
		else
			push_end(stack, value);
	}
}

/**
 * m_pall - prints all values on the stack
 * @stack: the stack to manipulate
 * @count: the line we are reading from in the file.
 * Return: nothing
 */
void m_pall(stack_t **stack, unsigned int count)
{
	stack_t *current;

	(void)count;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "Error: Stack is empty\n");
		return;
	}
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	free_my_stack(*stack);
}
