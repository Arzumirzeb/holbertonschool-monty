#include "monty.h"
/**
 * push - Something usefull
 * @stack: Something more usefull
 * @op: Something more usefull
 * @line_number: Something more usefull
 *
 * Return: Something much more usefull
 */
int push(stack_t **stack, char *op, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		return (1);
	}
	if (convert(op) == 1 && op != NULL)
	{
		new->n = atoi(op);
		new->prev = NULL;
		new->next = *stack;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free(new);
		return (1);
	}
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
	return (0);
}
