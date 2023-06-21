#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: head stack
 * @line_number: line number
 */

void	pop(stack_t **stack, unsigned int line_number)
{
	stack_t	*tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
