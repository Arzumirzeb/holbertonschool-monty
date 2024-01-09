#include "monty.h"
/**
 * _swap - swap top elements
 * @stack: stack
 * @counter: number of line
 */
void _swap(stack_t **stack, unsigned int counter)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
