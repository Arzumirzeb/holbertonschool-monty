#include "monty.h"
/**
 * exec_others - Something useful
 * @line_number: Something more useful
 * @op: Something more useful
 * @stack: Something more useful
 *
 * Return: Something much more usefull
 */
int exec_others(stack_t **stack, char *op, unsigned int line_number)
{
	int i = 0;
	instruction_t ins[] = {
								{"pall", pall},
								{"pint", pint},
								{"pop", pop},
								{"swap", swap},
								{"add", add},
								{"nop", nop},
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
		return (1);
	}
	return (0);
}
/**
 * execute - Something useful
 * @file: Something more useful
 * @stack: Something more useful
 *
 * Return: Something much more usefull
 */
int execute(FILE *file, stack_t **stack)
{
	char *buf = NULL, *tok = NULL;
	size_t size = 0;
	int line_count = 1, adam = 0;

	while (getline(&buf, &size, file) != -1 && adam != 1)
	{
		tok = strtok(buf, " \n\t\r$");
		if (tok == NULL || *tok == '#')
		{
			continue;
		}
		if (strcmp(tok, "push") == 0)
		{
			tok = strtok(NULL, " \n\t\r$");
			adam = push(stack, tok, line_count);
		}
		else
		{
			adam = exec_others(stack, tok, line_count);
		}
		line_count++;
	}
	free(buf);
	return (adam);
}
