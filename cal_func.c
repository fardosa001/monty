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
void cal_func(stack_t **stack, char *line_number, char *op, op_command_t *l, FILE *fd)
{
	int i = 0;
	instruction_t cal_op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	for (i = 0; cal_op[i].opcode != NULL; i++)
	{
		if (strcmp(cal_op[i].opcode, op) == 0)
		{
			if (strcmp(cal_op[i].opcode, "push") == 0)
			{
				if (is_digit(line_number) == -1)
				{
					fclose(fd);
					free_list(l);
					free_stack(*stack);
					fprintf(stderr, "L%d: usage: push integer\n", count);
					exit(EXIT_FAILURE);
				}
				else
					cal_op[i].f(stack, (unsigned int)atoi(line_number));
				return;
			}

			cal_op[i].f(stack, 0);
			return;
		}
	}
	fclose(fd);
	free_list(l);
	free_stack(*stack);
	fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
	exit(EXIT_FAILURE);
}
