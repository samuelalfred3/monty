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
	instruction_t matcher[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		{"stack", _stack}, {"queue", _queue}, {NULL, NULL},
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
		fprintf(stderr, "L%d: unknown command %s\n", count, oper);
		fclose(file);
		free(Ldata);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
