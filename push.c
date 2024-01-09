#include "monty.h"

/**
 * _push - adds a new node at the beginning of a stack_t list.
 * @opcode: opcode
 * @stack: top of the stack
 * @counter: line number
 * Return: void
 */
void _push(char *opcode, stack_t **stack, unsigned int counter)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return;
	}
	if (check_int(opcode) == 1 && opcode != NULL)
	{
		new->n = atoi(opcode);
		new->next = *stack;
		new->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;

}
