#include "monty.h"
#include <ctype.h>

char *arg_2;
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

	if (!arg_2)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (arg_2[0] != '-' || arg_2[0] != '+')
		i++;
	for (; arg_2[i] != '\0'; i++)
	{
		if (!isdigit(arg_2[i]))
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

	n = atoi(arg_2);
	new->n = n;
	new->prev = NULL;
	if (head)
	{
		head->prev = new;
		new->next = head;
	}
	else
	{
		new->next = NULL;
	}
	*stack = new;
}
