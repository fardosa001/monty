#include "monty.h"
/**
 * get_command - A fuction that returns a linked
 * list of struct of commands
 * @fd: file descriptor
 * Return: linked list or NULL if failed
 */
op_command_t *get_command(FILE *fd)
{
	char *cmd, *n, *linep = NULL;
	size_t a = 0;
	op_command_t *b = NULL;
	ssize_t lin;
	int i, all_spaces;


	lin = getline(&linep, &a, fd);
	while (lin > -1)
	{
		i = 0;
		all_spaces = 0;
		if (lin == 1)
		{
			lin = getline(&linep, &a, fd);
			continue;
		}
		while (linep[i] == ' ')
		{
			if (linep[i + 1] == '\n')
			{
				all_spaces = 1;
				break;
			}
			i++;
		}
		if (all_spaces == 0)
		{
			helper(linep, &cmd, &n);
			add_nodeint_end(&b, cmd, n);
			count++;
		}
		lin = getline(&linep, &a, fd);
	}
	free(linep);
	return (b);
}
/**
 * helper - A helper function.
 * @linep: the line
 * @cmd: pointer to save the opcode
 * @n: pointer to save the argument.
 */
void helper(char *linep, char **cmd, char **n)
{
	char *tk1, *tk2;

	tk1 = strtok(linep, " \n");
	if (tk1 == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}
	*cmd = strdup(tk1);
	tk2 = strtok(NULL, " \n");
	if (tk2 == NULL)
		*n = NULL;
	else
		*n = strdup(tk2);
}
/**
 * is_digit - A finction that checks if a sting is digit
 * @str: The string
 * Return: 0 if its string or -1 if its not
 */
int is_digit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}
