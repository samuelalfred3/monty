#include "monty.h"

/**
 * is_number - Check if a string represents a number.
 * @str: The input string to be checked.
 *
 * Return: 1 if the input string is a number, 0 otherwise.
 */

int is_number(char *str)
{
	if (str == NULL)
		return (0);

	while (*str)
	{
		unsigned int index = 0;

		if (*str == '-')
		{
			str++;
			continue;
		}

		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
