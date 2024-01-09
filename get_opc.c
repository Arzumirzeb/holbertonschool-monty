#include "monty.h"
/**
* get_op - get the opcode
* @token: opcode to get
* @stack: stack to use
* @counter: line of the opcode
* Return: void
*/

void get_op(char *token, stack_t **c_stack, unsigned int counter)
{
	int i = 0;

	instruction_t function[] = {
		{"pall", _pall},
		{NULL, NULL}
	};
	while (function[i].opcode)
	{
		if (strcmp(function[i].opcode, token) == 0)
		{
			function[i].f(c_stack, counter);
			break;
		}
		i++;

	}
	if (function[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, token);
		exit(EXIT_FAILURE);
	}
}
/**
 * check_int - check string if number
 * @opcode: string
 * Return: 1 if true, 0 if false
 *
 */

int check_int(char *opcode)
{
	unsigned int index = 0;

	if (opcode == NULL)
		return (0);
	while (opcode[index])
	{
		if (opcode[0] == '-')
		{
			index++;
			continue;
		}
		if (!isdigit(opcode[index]))
			return (0);
		index++;
	}
	return (1);
}
/**
 * free_stack - free a stack
 * @stack: head of the stack
 * Return: void
*/

void free_stack(stack_t *stack_head)
{
	stack_t *temp;

	while (stack_head != NULL)
	{
		temp = stack_head->next;
		free(stack_head);
		stack_head = temp;
	}

}
