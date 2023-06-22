#include "monty.h"
#include <ctype.h>


/**
 * stack_switch - set the linked list to LIFO mode
 * @stack: stack head
 * @line_number: line number
 */

void	stack_switch(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	params[1] = "stack";
}

/**
 * queue_switch - set the linked list to FIFO mode
 * @stack: stack head
 * @line_number: line number
 */

void	queue_switch(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	params[1] = "queue";
}
