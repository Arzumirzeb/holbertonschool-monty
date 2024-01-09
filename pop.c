#include "monty.h"
/**
 *
 */
void _pop(stack_t **stack, unsigned int counter)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", counter);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(temp);

}
