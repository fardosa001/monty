#include "monty.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on sucess
 */
int main(int ac, char **av)
{
	op_command_t *head, *next;
	FILE *fd;

	if (ac != 2)
	{
		/* print error and return what is required */
		return (0);
	}

	fd = fopen(av[1], "r");
	head = get_command(fd);
	print_listint(head);
	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
	free(head);

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
