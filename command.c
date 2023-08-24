#include "monty.h"
#include <stdio.h>
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


	lin = getline(&linep, &a, fd);
	while (lin > 0)
	{
		helper(linep, &cmd, &n);
		add_nodeint_end(&b, cmd, n);
		lin = getline(&linep, &a, fd);
	}
	free(linep);
	return (b);
}
void helper(char *linep, char **cmd, char **n)
{
	int i = 0;
	char *tk1, *tk2;

	tk1 = strtok(linep, " \n\t");
	if (tk1 == NULL)
	{
		printf(" error and return what is required \n");
		exit(-1);
	}
	*cmd = strdup(tk1);
	tk2 = strtok(NULL, " \n\t");
	if (tk2 == NULL)
	{
		*n = NULL;
		/*****EXECUTE SINGLE COMMAND i.e pall, swap, pop *****/
	} else
	{
		if (!tk2)
			*n = NULL;
		else
		{
			while (tk2[i])
			{
				if (tk2[i] < 48 || tk2[i] > 57)
				{
					printf(" error and return what is required \n");
					/*print error message */
					break;
				}
				i++;
			}
			*n = strdup(tk2);
		}

	}
}
/**void *remove_whitespaces(char *str)
{
	char *token;
	char *new_str = str;
	char temp[strlen(str) + 1];

	temp[0] = '\0';

	token = strtok(new_str, " ");

	while (token != NULL) {
	strcat(temp, token);
	token = strtok(NULL, " ");
	if (token != NULL) {
	    strcat(temp, " ");

	}

	strcpy(str, temp);
}*/
