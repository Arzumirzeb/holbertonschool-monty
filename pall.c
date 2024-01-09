#include "monty.h"
/**
 * _pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the head of the stack
 * @counter: line number
 * Return: void
 */
void _pall(stack_t **stack, unsigned int __attribute__((unused)) counter)
{
	stack_t *temp;

	if (!*stack)
		return;

	temp = *stack;
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
	*stack = temp;
}
