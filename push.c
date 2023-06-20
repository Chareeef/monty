#include "monty.h"

unsigned int line_n;
char **args;
/**
 * push - pushes an element the top of the stack
 * @stack: stack head
 * @line_number: line number
 */

void	push(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *new =  NULL;
	int n;

	printf("push\n");
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	n = atoi(args[2]);
	if (n == 0 && args[2][0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(args[2]);
	new->prev = NULL;
	new->next = head;
	head->prev = new;
	*stack = new;
	
}
