#include "monty.h"
/**
 * pint - Something usefull
 * @stack: Something more usefull
 * @line_number: Something more usefull
 *
 * Return: Something much more usefull
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
