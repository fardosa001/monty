#include "monty.h"
/**
 * pstr - prints str
 * @line_number: the line
 * @stack: the stack
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	s = *stack;
	while (s)
	{
		if (s->n < 33 || s->n > 127 || s->n == 0)
		{
			printf("\n");
			return;
		}
		printf("%c", s->n);
		s = s->next;
	}
	printf("\n");

}
