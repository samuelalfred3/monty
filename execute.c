#include "monty.h"

/**
 * execute - parses the line, finds corresponding opcode function, and executes
 * @line: the line from the Monty bytecode file
 * @stack: double pointer to the top of the stack
 * @line_number: the line number
 * @file: the Monty bytecode file
 * Return: no return
 */
void execute(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
	char *opcode;
	int i;
	int error_flag = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	opcode = strtok(line, " \n\t\r");
	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	error_flag = 1;
	free(line);
	free_stack(*stack);
	fclose(file);
	if (error_flag)
	{
		exit(EXIT_FAILURE);
	}
}
