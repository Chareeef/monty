#include "monty.h"
#include <ctype.h>

char *params[2];
/**
 * push - pushes an element the top of the stack
 * @stack: stack head
 * @line_number: line number
 */

void	push(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *new =  NULL;
	int n, i = 0;

	if (!params[0])
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (params[0][0] != '-' || params[0][0] != '+')
		i++;
	for (; params[0][i] != '\0'; i++)
	{
		if (!isdigit(params[0][i]) && params[0][i] != '-' && params[0][i] != '+')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	n = atoi(params[0]);
	new->n = n;
	new->prev = NULL;
	new->next = head;
	if (head)
		head->prev = new;
	*stack = new;

	if (strcmp(params[1], "queue") == 0)
		rotl(stack, line_number);
}
