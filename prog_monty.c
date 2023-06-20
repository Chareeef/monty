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
//		{"pop", pop},
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
