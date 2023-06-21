#include "monty.h"

/**
 * sub - substracts the second top element from the stack
 * by the top element of the stack.
 * @stack: head stack
 * @line_number: line number
 */
void	sub(stack_t **stack, unsigned int line_number)
{
	stack_t	*frst = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	frst = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= frst->n;
	free(frst);
}
/**
 * mul - multiplies the top two elements of the stack.
 * @stack: head stack
 * @line_number: line number
 */
void	mul(stack_t **stack, unsigned int line_number)
{
	stack_t	*frst = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	frst = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= frst->n;
	free(frst);
}

/**
 * divide - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: head stack
 * @line_number: line number
 */
void	divide(stack_t **stack, unsigned int line_number)
{
	stack_t	*frst = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	frst = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= frst->n;
	free(frst);
}

/**
 * modul - computes the rest of the divideision of the second top element
 * of the stack by the top element of the stack
 * @stack: head stack
 * @line_number: line number
 */
void	modul(stack_t **stack, unsigned int line_number)
{
	stack_t	*frst = NULL;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	frst = *stack;
	*stack = (*stack)->next;
	(*stack)->n %= frst->n;
	free(frst);
}
