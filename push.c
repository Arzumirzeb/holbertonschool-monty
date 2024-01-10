#include "monty.h"
/**
 * push - Something usefull
 * @stack: Something more usefull
 * @op: Something more usefull
 * @line_number: Something more usefull
 *
 */
void push(stack_t **stack, char *op, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		silgetsin(*stack);
		exit(EXIT_FAILURE);
		return;
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
		silgetsin(*stack);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}
