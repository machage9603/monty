#include "monty.h"
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
	char opcode[256];
	int value;
        char *line = NULL;
        size_t len = 0;
        unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, len, file) != NULL)
	{
		line_number++;
		if (sscanf(line, "%s %d", opcode, &value) == 2)
		{
			if (strcmp(opcode, "push") == 0)
			{
				push(&stack, value);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
	}
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
