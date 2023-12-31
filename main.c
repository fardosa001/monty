#include "monty.h"
int count = 1;
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on sucess
 */
int main(int ac, char **av)
{
	op_command_t *cmd_list, *cmd_copy;
	FILE *fd;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	cmd_list = get_command(fd);
	cmd_copy = cmd_list;
	count = 1;
	while (cmd_copy != NULL)
	{
		cal_func(&stack, cmd_copy->n, cmd_copy->cmd);
		cmd_copy = cmd_copy->next;
		count++;
	}
	free_list(cmd_list);
	free_stack(stack);
	fclose(fd);
	return (0);
}
/**
 * print_listint - A function that prints all the elements of a listint_t list.
 * @h: The list.
 * Return: the number of nodes.
 */
size_t print_listint(op_command_t *h)
{
	int numNodes = 0;

	while (h)
	{
		numNodes++;
		printf("%s ,%s\n", h->cmd, h->n);
		h = h->next;
	}
	return (numNodes);
}

/**
 * add_nodeint_end - A function that adds a new
 * node at the end of a listint_t list.
 * @head: The list.
 * @cmd: the opcode
 * @n: The number to be added to the list.
 * Return: the address of the new element
 * or NULL if it failed
 */
op_command_t *add_nodeint_end(op_command_t **head, char *cmd, char *n)
{
	op_command_t *new = malloc(sizeof(op_command_t));
	op_command_t *start = *head;

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->cmd = cmd;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	while (start->next)
	{
		start = start->next;
	}
	start->next = new;
	return (*head);
}
/**
 * free_list - A function that prints all the elements of a listint_t list.
 * @h: The list.
 * Return: the number of nodes.
 */
void free_list(op_command_t *h)
{
	op_command_t *next;

	if (!h)
		return;

	while (h)
	{
		next = h->next;
		free(h->cmd);
		if (h->n != NULL)
			free(h->n);
		free(h);
		h = next;
	}
}
