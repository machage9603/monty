#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct cmd_s - file and its content
 * @fd: file descriptor
 * @line: the line of the file
 */
typedef struct cmd_s
{
	FILE *fd;
	char *line;
} cmd_t;

extern cmd_t cmd;
extern int num;

void usage(int argc);
stack_t *newnode(int i);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void clear_stack(stack_t **stack);
void interpretor(char *argv);
int get_opc(stack_t **stack, char *arg, char *val, int line_number);
void open_error(char *file);
void push_error(FILE *fd, char *line, stack_t *stack, int line_number);
void inst_error(FILE *fd, char *line, stack_t *stack, char *val, int line_n);
int is_digit(char *c);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void divd(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

#endif
