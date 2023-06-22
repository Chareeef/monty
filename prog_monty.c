#include "monty.h"

/**
 * free_stack - free a stack
 * @stack: pointer to pointer to the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *head;
	stack_t *temp;

	if (!stack)
		exit(EXIT_FAILURE);

	head = *stack;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * print_error - print an error message and exit
 * @code: error code
 * @argv_0: argv[1]
 * @opcode: opcode string
 * @line_n: line number
 */

void print_error(int code, char *argv_0, char *opcode, int line_n)
{
	switch (code)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 1:
			fprintf(stderr, "Error: Can't open file %s\n", argv_0);
			break;
		case 2:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode);
			break;
	}

	exit(EXIT_FAILURE);
}

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
	char line[500], *opcode = NULL;
	instruction_t instructions[] = INSTRUCTIONS;

	params[1] = "stack";
	if (argc != 2)
		print_error(0, NULL, NULL, 0);
	file = fopen(argv[1], "r");
	if (!file)
		print_error(1, argv[1], NULL, 0);
	for (; fgets(line, sizeof(line), file);
			line_n++, func = NULL, opcode = NULL)
	{
		opcode = strtok(line, " \n");
		if (!opcode || opcode[0] == '#')
			continue;
		params[0] = strtok(NULL, " \n");
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
			print_error(2, NULL, opcode, line_n);
	}
	free_stack(&stack);
	fclose(file);
	return (0);
}
