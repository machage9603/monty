#include "monty.h"

/**
 * is_digit - checks if it is a digit
 * @c: the parameter
 * Return: 0 or 1
 **/

int is_digit(char *c)
{
	char *temp = c;

	if (c == NULL)
		return (0);
	if (*temp == '-')
		temp++;

	for (; *temp != '\0'; temp++)
	{
		if ((*temp < '0' || *temp > '9'))
		{
			return (0);
		}
	}
	return (1);
}
