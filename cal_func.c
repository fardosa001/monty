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
void cal_func(stack_t **stack, unsigned int line_number, char **op)
{
	instruction_t cal_op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int i = 0;

	while (cal_op[i].opcode != NULL)
	{
		if (strcmp(cal_op[i].opcode, op) == 0)
		{
			cal_op[i].f(stack, line_number);
			return;
		}
		i++;
	}

	printf("L%d: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
