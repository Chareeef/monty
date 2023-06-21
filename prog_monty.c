#include "monty.h"

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0 on Success
 */

int main(int argc, char **argv)
{
	FILE *file = NULL;
	stack_t *stack = NULL;
	void (*func)(stack_t **stack, unsigned int line_number) = NULL;
	int i, line_n = 1;
	char line[100], *opcode;
	instruction_t instructions[] = INSTRUCTIONS;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (; fgets(line, sizeof(line), file); line_n++, func = NULL)
	{
		opcode = strtok(line, " \n");
		if (!opcode)
			continue;
		arg_2 = strtok(NULL, " \n");
		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				func = instructions[i].f;
				break;
			}
		}
		if (func)
			func(&stack, line_n);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode);
		exit(EXIT_FAILURE);
	}
	return (0);
}
