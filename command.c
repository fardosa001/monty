#include "monty.h"
/**
 * get_command - A fuction that returns a linked
 * list of struct of commands
 * @fd: file descriptor
 * Return: linked list or NULL if failed
 */
op_command_t *get_command(FILE *fd)
{
	char *linep = NULL;
	size_t a = 0;
	op_command_t *b = NULL, *newnode = malloc(sizeof(op_command_t));

	if (newnode == NULL)
	{
		/* print error and return what is required */
		return (NULL);
	}

	while (getline(&linep, &a, fd) != -1)
	{
		helper(linep, &newnode);
		printf("%s, %s\n", newnode->cmd, newnode->n);
		if (b == NULL)
			b = newnode;
		else
		{
			while (b->next)
				b = b->next;
			b->next = newnode;
		}
	}
	free(linep);
	return (b);
}
void helper(char *linep, op_command_t **newnode)
{
	int i = 0;
	char *tk1, *tk2;
	op_command_t *node = *newnode;

	tk1 = strtok(linep, " \n\t");
	if (tk1 == NULL)
	{
		printf(" error and return what is required \n");
		exit(-1);
	}
	node->cmd = tk1;
	tk2 = strtok(NULL, " \n\t");
	if (tk2 == NULL)
	{
		node->n = NULL;
		/*****EXECUTE SINGLE COMMAND i.e pall, swap, pop *****/
	} else
	{
		if (!tk2)
			node->n = NULL;
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
			node->n = tk2;
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
