#include "monty.h"

/**
 * main - The code of the program
 * @argv: main args array
 * @argc: main args array
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	e_info data = {NULL, NULL, NULL, 0};
	FILE *file;
	char *Ldata;
	size_t Lsize = 0;
	ssize_t crnt_line = 1;
	unsigned int count = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	data.file = file;
	while (crnt_line > 0)
	{
		Ldata = NULL;
		crnt_line = getline(&Ldata, &Lsize, file);
		count++;

		if (crnt_line > 0 && Ldata[0] != '#')
		{
			cmd_executer(file, Ldata, &stack, count);
		}
		free(Ldata);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
