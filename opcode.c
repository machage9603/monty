#include "monty.h"

/**
 * get_opc - gets the opcode function
 * @stack: pointer to the top of stack
 * @arg: the argument
 * @val: the value
 * @line_number: the line number
 * Return: 0 on success || 1 if not a digit || -1 on error
 */

int get_opc(stack_t **stack, char *arg, char *val, int line_number)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", divd},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};
	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (is_digit(val) == 1)
					num = atoi(val);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (-1);

	return (0);
}
