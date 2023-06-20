#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: head stack
 * @line_number: line number
 */

void	add(stack_t **stack, unsigned int line_number)
{
	stack_t	*frst = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	frst = *stack;
	*stack = (*stack)->next;
	(*stack)->n += frst->n;
	free(frst);
}
