#include "monty.h"
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: the arguments
 * Return: 0(success) else error set appropriately
 */
int main(int argc, char **argv)
{

	usage(argc);

	interpretor(argv[1]);

	return (0);
}
