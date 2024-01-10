#include "monty.h"
/**
 * pall - Something usefull
 * @stack: Something more usefull
 * @line_number: Something more usefull
 *
 * Return: Something much more usefull
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *zor;
	int i = 0;
	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}
	zor = *stack;
	while (zor != NULL)
	{
		if (zor != NULL)
		{
			printf("%d\n", zor->n);
		}
		zor = zor->next;
		i++;
	}
}
