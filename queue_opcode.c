#include "monty.h"

/**
 * queue - This sets the format of the data to a queue (FIFO)
 * @stack: Stack to manipulate (unused)
 * @count: Line number (unused)
 * Return: Nothing
 */
void queue(stack_t **stack, unsigned int count)
{
	(void)stack;
	(void)count;
	data.mode = QUEUE_MODE;
}
