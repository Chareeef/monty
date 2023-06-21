#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INSTRUCTIONS {		\
	{"pint", pint},	\
	{"pall", pall},	\
	{"nop", nop},	\
	{"swap", swap},	\
	{"pop", pop},	\
	{"add", add},	\
	{"push", push},	\
	{NULL, NULL}	\
}

extern char *arg_2;

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

void	print_error(int code, char *argv_1, char *opcode, int line_n);
void	pop(stack_t **stack, unsigned int line_number);
void	pint(stack_t **stack, unsigned int line_number);
void	pall(stack_t **stack, unsigned int line_number);
void	nop(stack_t **stack, unsigned int line_number);
void	push(stack_t **stack, unsigned int line_number);
void    swap(stack_t **stack, unsigned int line_number);
void    add(stack_t **stack, unsigned int line_number);

#endif
