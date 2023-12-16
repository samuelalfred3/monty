#include "monty.h"

/**
 * m_queue - Sets the format of the data to a queue (FIFO)
 * @stack: Unused parameter (avoid compiler warnings)
 * @count: Unused parameter (avoid compiler warnings)
 * Return: Nothing
 */
void m_queue(stack_t **stack, unsigned int count)
{
	(void)stack;
	(void)count;
	data.mode = QUEUE_MODE;
}
