#include "monty.h"

/**
 * push - pushes an element the top of the stack
 * @stack: stack head
 * @line_number: line number
 */

void	push(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *new =  NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->prev = NULL;
	new->next = head;
	head->prev = new;
	*stack = new;
	
}
