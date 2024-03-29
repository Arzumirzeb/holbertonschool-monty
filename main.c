#include "monty.h"
/**
 * main - Something usefull
 * @argc: Something more usefull
 * @argv: Something more usefull
 *
 * Return: Something much more usefull
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	int adam = 0;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	adam = execute(file, &stack);
	silgetsin(stack);
	fclose(file);
	if (adam == 1)
	{
		exit(EXIT_FAILURE);
	}
	return (0);
}
