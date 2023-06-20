#include "monty.h"

void	pop(stack_t **stack, unsigned int line_number)
{
	int	tmp;
	stack_t	ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	ptr = tmp;
	tmp = (*stack)->next;
	free(ptr);
}
