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
		{NULL, NULL}
	};

	for (i = 0; cal_op[i].opcode != NULL; i++)
	{
		if (strcmp(cal_op[i].opcode, op) == 0)
		{
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
