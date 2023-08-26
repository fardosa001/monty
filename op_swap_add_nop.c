#include "monty.h"
/**
 * swap - swaps the top two elements
 * of stack of the stack
 * @stack: stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int c;

	(void)line_number;
	if ((*stack)->next == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	c = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = c;
}
/**
 * add - adds the top two elements
 * of stack of the stack
 * @stack: stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	(void)line_number;
	if ((*stack)->next == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	(*stack)->next->n += (*stack)->n;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	free(t);
}
