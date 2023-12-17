#include "monty.h"
#define SEPARATORS "\n "

/**
 * exec_command - Is a command executor
 * @file: File
 * @Ldata: Line
 * @stack: Stack to manipulate
 * @count: Line number
 * Return: 0 on success or 1 on failure
*/
int exec_command(FILE *file, char *Ldata, stack_t **stack, unsigned int count)
{
	(void)file;
	instruction_t matcher[] = {
		{"push", m_push}, {"pall", m_pall}, {"pint", m_pint},
		{"pop", m_pop}, {"swap", m_swap}, {"add", m_add},
		{"nop", m_nop}, {"sub", m_sub}, {"div", m_div},
		{"mul", m_mul}, {"mod", m_mod}, {"pchar", m_pchar},
		{"pstr", m_pstr}, {"rotl", m_rotl}, {"rotr", m_rotr},
		{"stack", m_stack}, {"queue", m_queue}, {NULL, NULL},
	};
	unsigned int i = 0;
	char *oper = strtok(Ldata, SEPARATORS);

	if (oper && oper[0] == '#')
	{
		free(Ldata);
		return (0);
	}
	data.token = strtok(NULL, SEPARATORS);
	while (oper && matcher[i].opcode)
	{
		if (strcmp(oper, matcher[i].opcode) == 0)
		{
			matcher[i].f(stack, count);
			free(Ldata);
			return (0);
		}
		i++;
	}
	if (oper && matcher[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: Error - Unknown command %s\n", count, oper);
		free(Ldata);
		return (1);
	}
	return (0);
}
