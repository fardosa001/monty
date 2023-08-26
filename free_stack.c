#include "monty.h"

/**
 * free_stack - frees the stack memory
 * @stack: stack to be freed
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = stack;
	stack_t *current;

	if (!stack)
		return;
	while (temp != NULL)
	{
		current = temp->next;
		free(temp);
		temp = current;
	}
}

