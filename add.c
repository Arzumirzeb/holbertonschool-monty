#include "monty.h"
/**
 * _add - add 2 top elements
 * @stack: stack
 * @counter: numberof line
 */
void _add(stack_t **stack, unsigned int counter)
{
	int sum, first, second;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	top = (*stack);
	first = top->n;
	second = top->next->n;
	sum = first + second;
	top->next->n = sum;
	*stack = top->next;
	free(top);
}
