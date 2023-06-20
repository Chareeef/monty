#include "monty.h"

int main(int argc __attribute__((unused)), char **argv)
{
	stack_t *stack = NULL;
	void (*func)(stack_t **stack, unsigned int line_number) = NULL;
	int i;
	instruction_t instructions[] = {
		{"pint", pint},
		{"pall", pall},
		{"nop", nop},
		{"swap", swap},
		{"pop", pop},
		{"push", push},
		{NULL, NULL}
	};

	args = argv;
	line_n = 1;
	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(args[1], instructions[i].opcode) == 0)
		{
			func = instructions[i].f;
			break;
		}
	}

	if (func)
		func(&stack, line_n);
	line_n++;
		

	return (0);
}
