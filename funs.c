#include "monty.h"
/**
 * convert - Something usefull
 * @op: Something more usefull
 *
 * Return: Something much more usefull
 */
int convert(char *op)
{
	unsigned int i = 0;

	if (op == NULL)
	{
		return (0);
	}
	while (op[i])
	{
		if (op[0] == '-')
		{
			i++;
			continue;
		}
		if (isdigit(op[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/**
 * silgetsin - Something usefull
 * @stack: Something more usefull
 *
 * Return: Something much more usefull
 */
void silgetsin(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
