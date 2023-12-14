#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global - Global variables used in the Monty interpreter
 * @argument: The argument associated with the current instruction
 * @line_number: The line number of the current instruction in the Monty file
 *
 * Description: This structure holds global variables that need to be shared
 * across different parts of the Monty interpreter, such as the current
 * argument being processed and the line number of the current instruction.
 */
struct global
{
	char *argument;
	unsigned int line_number;
};
extern struct global global;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void execute(char *line, stack_t **stack, unsigned int line_number, FILE* file);
void free_stack(stack_t *stack);

#endif /* MONTY_H */
