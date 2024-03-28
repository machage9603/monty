#include "monty.h"

cmd_t cmd = {NULL, NULL};

/**
 *interpretor - reads the file and executes the monty bytecodes
 *@argv: argument vector
 */

void interpretor(char *argv)
{
	int line = 0, r = 0;
	size_t size = 0;
	char *token = NULL;
	char *val = NULL;
	stack_t *stack = NULL;

	cmd.fd = fopen(argv, "r");
	if (cmd.fd)
	{
		while (getline(&cmd.line, &size, cmd.fd) != -1)
		{
			line++;
			token = strtok(cmd.line, " \n\t\r");
			if (token == NULL)
			{
				free(token);
				continue;
			}
			else if (*token == '#')
			{
				continue;
			}
			val = strtok(NULL, " \n\t\r");
			r = get_opc(&stack, token, val, line);

			if (r == 1)
				push_error(cmd.fd, cmd.line, stack, line);
			else if (r == -1)
				inst_error(cmd.fd, cmd.line, stack, token, line);
		}
		free(cmd.line);
		free_stack(stack);
		fclose(cmd.fd);
	}
	else
	{

		open_error(argv);

	}
}
