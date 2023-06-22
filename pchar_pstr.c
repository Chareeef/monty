#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to pointer to the top of the stack
 * @line_number: file's line number
 */

void	pchar(stack_t **stack, unsigned int line_number)
{
	stack_t	*top;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (!isascii(top->n))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", top->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: pointer to pointer to the top of the stack
 * @line_number: file's line number
 */

void	pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t	*top;

	if (!stack)
		return;

	top = *stack;

	while (top)
	{
		if (!top->n || !isascii(top->n))
			break;

		printf("%c", top->n);
		top = top->next;
	}

	printf("\n");
}
