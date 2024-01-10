#include "monty.h"
/**
 * swap - Something usefull
 * @stack: Something more usefull
 * @line_number: Something more usefull
 *
 * Return: Something much more usefull
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *temp = *stack;

	if (*stack != NULL)
	{
		a = temp->n;
		temp = temp->next;
		b = temp->n;
		temp->n = a;
		temp = temp->prev;
		temp->n = b;
		*stack = temp;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
