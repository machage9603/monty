#include "monty.h"
/**
  *rotr - rotateTo the bottom
  *@stack: pointer to top of stack
  *@line_number: line number in the file
  *Return: no return
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;

	copy = *stack;
	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
