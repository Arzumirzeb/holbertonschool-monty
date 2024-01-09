#include "monty.h"
/**
 * _pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the head of the stack
 * @counter: line number
 * Return: void
 */
void _pall(stack_t **stack, unsigned int __attribute__((unused)) counter)
{
	int index = 0;
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		if (temp != NULL)
		{
			printf("%d\n", temp->n);
		}
		index++;
		temp = temp->next;
	}
}
