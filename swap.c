#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: head stack
 * @line_number: line number
 */

void	swap(stack_t **stack, unsigned int line_number)
{
	int	temp;

	if (!*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
