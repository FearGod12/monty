#include "monty.h"

/**
 * check_if_integer - checks if a string contains a number
 * @arg: string to be checked
 * Return: 1 if true or 0 if false
 */
int check_if_integer(char *arg)
{
	int i = 0;

	while (*(arg + 1) != '\0')
	{
		if (*(arg + 1) >= '0' && *(arg + 1) <= '9')
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/**
 * get_strtok - tokenizes a line
 * @line: line to be tokenised
 * @line_number: line number of the line to be tokenised
 * Return: token
 */
char *get_strtok(char *line, unsigned int line_number)
{
	char delim[2] = "\n ";
	char *token = NULL;
	char *arg = NULL;

	token = strtok(line, delim);
	if (!token)
		return NULL;
	arg = strtok(NULL, delim);
	if (arg)
	{
		if (check_if_integer(arg))
			global_var = atoi(arg);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
	else if (arg == NULL && (strcmp(token, "push") == 0))
	{
		fprintf(stderr, "L%d: unknown instruction %s", line_number, token);
		exit(EXIT_FAILURE);
	}
	return (token);
}
