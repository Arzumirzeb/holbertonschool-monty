#include "monty.h"
/**
 * exec_others - Something useful
 * @line_number: Something more useful
 * @op: Something more useful
 * @stack: Something more useful
 *
 * Return: Something much more useful
 */
void exec_others(stack_t **stack, char *op, unsigned int line_number)
{
	int i = 0;
	instruction_t ins[] = {
								{"pall", pall},
								{NULL, NULL}
	};

	while (ins[i].opcode != NULL)
	{
		if (strcmp(ins[i].opcode, op) == 0)
		{
			ins[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (ins[i].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}
/**
 * execute - Something useful
 * @file: Something more useful
 * @stack: Something more useful
 *
 * Return: Something much more useful
 */
void execute(FILE *file, stack_t **stack)
{
	char *buf, *tok = NULL;
	size_t size = 0;
	int line_count = 1;

	while (getline(&buf, &size, file) != -1)
	{
		tok = strtok(buf, " \n\t\r");
		if (tok == NULL || *tok == '#')
		{
			continue;
		}
		if (strcmp(tok, "push") == 0)
		{
			tok = strtok(NULL, " \n\t\r");
			push(stack, tok, line_count);
		}
		else
		{
			exec_others(stack, tok, line_count);
		}
		line_count++;
	}
	free(buf);
}
