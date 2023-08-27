#include "monty.h"
/**
 * cal_func - function to execute operation functions
 * @stack: stack
 * @op: opcode
 * @line_number: line_number
 *
 * Return: pointer to correct function
 *
 */
void cal_func(stack_t **stack, char *line_number, char *op)
{
	int i = 0;
	instruction_t cal_op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", NULL},
		{"sub", sub},
		{"mul", mul},
		{"div", div_func},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	if (op[0] == '#')
		return;
	for (i = 0; cal_op[i].opcode != NULL; i++)
	{
		if (strcmp(cal_op[i].opcode, op) == 0)
		{
			if (strcmp(cal_op[i].opcode, "nop") == 0)
				return;
			if (strcmp(cal_op[i].opcode, "push") == 0)
			{
				handle_push(stack, line_number, cal_op[i].f);
				return;
			}

			cal_op[i].f(stack, 0);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
	exit(EXIT_FAILURE);
}

/**
 * handle_push - handles push
 * @stack: the stack
 * @line_number: line number
 * @f: function pointer to push
 */
void handle_push(stack_t **stack, char *line_number,
		void (*f)(stack_t **stack,
			unsigned int line_number))
{
	if (is_digit(line_number) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}
	else
		f(stack, (unsigned int)atoi(line_number));
}
/**
 * mod -  mod the top element of the stack
 * from the second top element of the stack.
 * @stack: stack
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	(*stack)->next->n %= (*stack)->n;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(t);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 33 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
