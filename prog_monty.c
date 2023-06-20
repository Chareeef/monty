#include "monty.h"

/**
 * main - entry point
 * @argc: unused
 * @argv: arguments
 * Return: 0
 */

int main(int argc __attribute__((unused)), char **argv)
{
	FILE *file = NULL;
	stack_t *stack = NULL;
	void (*func)(stack_t **stack, unsigned int line_number) = NULL;
	int i, line_n;
	char line[100], *opcode;

	instruction_t instructions[] = INSTRUCTIONS;

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_n = 1;
	while (fgets(line, sizeof(line), file))
	{
		for (i = 0; line[i]; i++)
		{
			if (line[i] == '\n')
				line[i] = '\0';
		}
		opcode = strtok(line, " ");
		arg_2 = strtok(NULL, " ");
		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				func = instructions[i].f;
				break;
			}
			else
				func = NULL;
		}
		if (func)
			func(&stack, line_n);
		else
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode);
		line_n++;
	}
	return (0);
}
