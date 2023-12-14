#include "monty.h"

/**
 * get_global - Get the global variable
 *
 * Return: Pointer to the global variable
 */

struct global *get_global(void)
{
	static struct global global;

	return (&global);
}
