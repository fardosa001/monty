#include "monty.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on sucess
 */
int main(int ac, char **av)
{
	op_command_t *head;
	FILE *fd;
	size_t num;

	if (ac != 2)
	{
		/* print error and return what is required */
		return (0);
	}

	fd = fopen(av[1], "r");
	head = get_command(fd);
	/**Your code goes here
	 * head is a linled list containig commands.
	 *
	 * loop through each item in list "head"
	 * for each node in head loop through opcode list and compare if head->cmd == instructions_t
	 * 	if true
	 * 		call the fuction pointer of instruction_t->f
	 * 			opcodefound = 1
	 * 			pass head->cmd as argument and atoi(head->n)
	 * 	if false
	 * 		continue looping for the next item in head list
	 * 
	 * Not done with pseudocode but it will give you an idea of how to do it*/




	/* Remove this num and printf  for tou to stop printing list*/
	num = print_listint(head);
	printf("%ld\n", num);
	free_list(head);
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
		free(h->n);
		free(h);
		h = next;
	}
}
