#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * struct execution_info - struct that stores the execution Information needed.
 * @file: The file read from.
 * @content:The line read from the file
 * @token: Passed with the opcode value
 * @mode: Inserting mode (Stack / Queue)
 */
typedef struct execution_info
{
	FILE *file;
	char *content;
	char *token;
	int mode;
} e_info;

extern e_info data;

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

/* stack_ops.c */
void push(stack_t **stack, unsigned int count);
void pall(stack_t **stack, unsigned int count);

/* nop_opcode */
void nop(stack_t **stack, unsigned int count);

/* add_opcode.c */
void add(stack_t **stack, unsigned int count);

/* div_opcode.c */
void div(stack_t **stack, unsigned int count);

/* mod_opcode.c */
void mod(stack_t **stack, unsigned int count);

/* mul_opcode.c */
void mul(stack_t **stack, unsigned int count);

/* pint_opcode.c */
void pint(stack_t **stack, unsigned int count);

/* pop_opcode.c */
void pop(stack_t **stack, unsigned int count);

/* sub_opcode.c */
void sub(stack_t **stack, unsigned int count);

/* swap_opcode.c */
void swap(stack_t **stack, unsigned int count);

/* queue_opcode.c */
void queue(stack_t **stack, unsigned int count);

/* pstr_opcode_impl.c */
void pstr(stack_t **stack, unsigned int count);

/* pchar_opcode_impl.c */
void pchar(stack_t **stack, unsigned int count);

/* number_utils.c */
int is_number(char *str);

/* monty_interpreter.c */
int exec_command(FILE *file, char *Ldata, stack_t **stack, unsigned int count);

/* rotl_opcode_impl.c */
void rotl(stack_t **stack, unsigned int count);

/* rotr_opcode_impl.c */
void rotr(stack_t **stack, unsigned int count);

/* stack_ops2.c */
void stack(stack_t **stack, unsigned int count);
void free_stack(stack_t *stack);
size_t stack_len(const stack_t *h);

/* stack_ops3.c */
void push_start(stack_t **stack, int n);
void push_end(stack_t **stack, const int n);


#endif /* MONTY_H */
