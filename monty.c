#include "monty.h"
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char *arg;
	FILE *stream;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	arg = argv[1];

	stream = fopen(arg, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg);
		exit(EXIT_FAILURE);
	}
	get_read(stream, &stack);
	free_stack(stack);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

/**
 * get_read - read code
 * @stream: file
 * @stack: stack
 * Return: Nothing
 *
 */
void get_read(FILE *stream, stack_t **stack)
{
	char *opcode, *token = NULL;
	size_t len = 0;
	int counter = 0;

	while (getline(&opcode, &len, stream) != -1)
	{
		counter++;
		token = strtok(opcode, " \n\t\r");
		if (!token || *token == '#')
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n\t\r");
			_push(token, stack, counter);
		}
		else
		{
			get_op(token, stack, counter);
		}
	}
	free(opcode);
}
