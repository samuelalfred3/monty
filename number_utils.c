#include "monty.h"

/**
 * is_number - Check if a string represents a number.
 * @str: The input string to be checked.
 *
 * Return: 1 if the input string is a number, 0 otherwise.
 */
int is_number(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
