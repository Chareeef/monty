#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INSTRUCTIONS {		\
	{"pint", pint},	\
	{"pall", pall},	\
	{"nop", nop},	\
	{"swap", swap},	\
	{"pop", pop},	\
	{"push", push},	\
	{"add", add},	\
	{"mul", mul},	\
	{"sub", sub},	\
	{"div", divide},	\
	{"mod", modul},	\
	{"pchar", pchar},	\
	{"pstr", pstr},	\
	{"rotl", rotl},	\
	{"rotr", rotr},	\
	{"stack", stack_switch},	\
	{"queue", queue_switch},	\
	{NULL, NULL}	\
}

extern char *params[2];

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
void	free_stack(stack_t **stack);
void	pop(stack_t **stack, unsigned int line_number);
void	pint(stack_t **stack, unsigned int line_number);
void	pall(stack_t **stack, unsigned int line_number);
void	nop(stack_t **stack, unsigned int line_number);
void	push(stack_t **stack, unsigned int line_number);
void    swap(stack_t **stack, unsigned int line_number);
void    add(stack_t **stack, unsigned int line_number);
void    mul(stack_t **stack, unsigned int line_number);
void    sub(stack_t **stack, unsigned int line_number);
void    divide(stack_t **stack, unsigned int line_number);
void    modul(stack_t **stack, unsigned int line_number);
void    pchar(stack_t **stack, unsigned int line_number);
void    pstr(stack_t **stack, unsigned int line_number);
void    rotl(stack_t **stack, unsigned int line_number);
void    rotr(stack_t **stack, unsigned int line_number);
void    stack_switch(stack_t **stack, unsigned int line_number);
void    queue_switch(stack_t **stack, unsigned int line_number);

#endif
