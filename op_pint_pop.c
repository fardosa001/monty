#include "monty.h"

/**
 *pint - prints the value at the top of the stack
 *@stack: stack
 *@line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pint,stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - removes top element of the stack
 * @stack: stack
 * @line_number: line_number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = *stack;
		*stack = tmp->next;
		if (*stack != NULL)
		(*stack)->prev = NULL;

		free(tmp);
	}
}
