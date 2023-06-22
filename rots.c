#include "monty.h"

/**
 * rotl -  rotates the stack to the top.
 * @stack: head stack
 * @line_number: line number
 */

void	rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t	*current;
	stack_t	*top;

	if (*stack && (*stack)->next)
	{
		top = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = top;
		top->prev = current;
		top->next = NULL;
	}
}

/**
 * rotr -  rotates the stack to the top.
 * @stack: head stack
 * @line_number: line number
 */

void	rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t	*bottom;
	stack_t	*current;

	if (*stack && (*stack)->next)
	{
		current = (*stack)->next;
		while (current->next)
			current = current->next;
		bottom = current;
		current = current->prev;
		current->next = NULL;
		bottom->next = *stack;
		bottom->prev = NULL;
		*stack = bottom;
	}
}
