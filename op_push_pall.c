#include "monty.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * push - pushes an element to the stack
 * @stack: stack
 * @line_number: line number
 * @val: value
 */
void push(stack_t **stack, unsigned int line_number, int val)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error: malloc failed\n")
			exit(EXIT_FAILURE);

	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall - prints all the vallues on the stack from top
 * @stack: the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (*stack == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

}
