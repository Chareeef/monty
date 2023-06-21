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
		print_error(1, NULL, NULL, 0);
	file = fopen(argv[1], "r");
	if (!file)
		print_error(2, argv[1], NULL, 0);
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
		else
			print_error(3, NULL, opcode, line_n);
	}
	return (0);
}

/**
 * print_error - print an error message and exit
 * @code: error code
 * @argv_1: argv[1]
 * @opcode: opcode string
 * @line_n: line number
 */

void print_error(int code, char *argv_1, char *opcode, int line_n)
{
	switch (code)
	{
		case 1:
			fprintf(stderr, "Usage: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", argv_1);
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode);
			break;
	}

	exit(EXIT_FAILURE);
}
