#include "monty.h"
/**
 * usage - entry point
 * @argc: the arguments count
 * Return: void
 */
void usage(int argc)
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 *open_error - prints error message when open file fail
 *@file: file
 * Return: void
 */

void open_error(char *file)
{
	dprintf(2, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);

}

/**
 * push_error - prints error when push to stack fail
 * @fd: file desciptor
 * @line: buffer
 * @stack:  pointer to stack
 * @line_number: line number of the command
 */

void push_error(FILE *fd, char *line, stack_t *stack, int line_number)
{
	dprintf(2, "L%u: usage: push integer\n", line_number);
	fclose(fd);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * inst_error - handles unknown instructions
 * @fd: file descriptor
 * @line: buffer
 * @stack:  pointer to the stack
 * @line_n: line number of the command
 * @val: instruction
 */

void inst_error(FILE *fd, char *line, stack_t *stack, char *val, int line_n)
{
	dprintf(2, "L%u: unknown instruction %s\n", line_n, val);
	fclose(fd);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
