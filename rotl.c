#include "monty.h"
/**
  *rotl - rotates Stack
  *@stack: top
  *@line_number: line number in file
  *Return: no return
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *total;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	total = (*stack)->next;
	total->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = total;
}
