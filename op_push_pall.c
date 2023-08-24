#include "monty.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * push - pushes an element to the stack
 * @stack: stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_elem;
	int val = globalVal;
	
	(void) line_number;

	new_elem = malloc(sizeof(stack_t));
	if (new_elem == NULL)
		printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);

	new_elem->n = val;
	new_elem->prev = NULL;
	new_elem->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_elem;
	}
	*stack = new_elem;
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
