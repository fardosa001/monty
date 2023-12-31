#define _GNU_SOURCE
#ifndef MONTY_H
#define MONTY_H

extern int count;
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer to be casted to unsigned it 
 * @cmd: the opcode
 * @next: points to the next element of the list
 * Description: Singly linked list node structure
 * containing commands and the number
 */
typedef struct op_command_s
{
	char *n;
	char *cmd;
	struct op_command_s *next;
} op_command_t;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void handle_push(stack_t **stack, char *line_numb,
		void (*f)(stack_t **stack,
			unsigned int line_number));

void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_func(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
op_command_t *add_nodeint_end(op_command_t **head, char *cmd, char *n);
size_t print_listint(op_command_t *h);
op_command_t *get_command(FILE *fd);
int is_digit(char *str);
void free_list(op_command_t *h);
void helper(char *linep, char **cmd, char **n);
void push(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void cal_func(stack_t **stack, char *line_number, char *op);
void pop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

#endif
