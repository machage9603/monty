#include "monty.h"
/**
 * swap - swaps the top 2 elemets of stack
 * @stack: pointer to the top of stack
 * @line_number: the line number in file
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int n = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		n = temp->n;
		temp->n = temp->next->n;
		temp->next->n = n;
	}
}
/**
 * nop - function that does nothing
 * @stack: pointer to the top of stack
 * @line_number: the line number of file
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * add - sums up the top 2 values in the stack
 * @stack: pointer to the top of stack
 * @line_number: the line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int sum = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	sum += (*stack)->next->n;
	sum += (*stack)->n;
	pop(stack, line_number);
	temp->n = sum;
}
/**
 * sub - substracts the fir two values in the stack
 * @stack: the pointer to top of stack
 * @line_number: the line in the file
 * Return: viod
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	result = temp->n;
	result -= (*stack)->n;
	pop(stack, line_number);
	temp->n = result;
}
/**
 * divd - divides the first two elements of stack
 * @stack: pointer to top of stack
 * @line_number: the line number in monty file
 * Return: void
 */
void divd(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
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
	result /= (*stack)->n;
	pop(stack, line_number);
	temp->n = result;
}
