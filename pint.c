#include "monty.h"

/**
 * _pint - print elements
 * @stack: stack
 * @counter: numler of line
 */
void _pint(stack_t **stack, unsigned int counter)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
