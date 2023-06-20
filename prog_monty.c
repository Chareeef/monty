#include "monty.h"

int main(int argc __attribute__((unused)), char **argv)
{
	stack_t **stack = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);
	int i;
	instruction_t instructions[] = {
		{"pint", pint},
		{"pall", pall},
		{"nop", nop},
//		{"swap", swap},
//		{"pop", pop},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(argv[1], instructions[i].opcode) == 0)
			func = instructions[i].f;
	}

	if (func)
		func(stack, atoi(argv[2]));
		

	return (0);
}
