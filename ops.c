#include "monty.h"
/**
 * pchar - prints the top element of the stack in char
 * @stack: the pointer to the top of stack
 * @line_number: the line number in the file
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * mul - multiplies the first 2 top elements
 * @stack: the pointer to the stack
 * @line_number: the line number in monty file
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	result = temp->n * (*stack)->n;
	pop(stack, line_number);
	temp->n = result;
}
/**
 * mod - calculates modulus of the top 2 elements
 * @stack: pointer to the top of stack
 * @line_number: the line number in a file
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	result = temp->n;
	result %= (*stack)->n;
	pop(stack, line_number);
	temp->n = result;
}
