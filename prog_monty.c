#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	stack_t *stack_t;
	void (*func)(stack_t **stack, unsigned int line_number);
	int i;
	instruction_t instructions[] = {
		{"pint", pint},
		{"push", push},
		{"pop", pop},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(argv[0], instructions[i].opcode) == 0)
			func = instructions[i].f;
	}

	if (func)
		func(stack, atoi(argv[1]));

	return (0);
}
