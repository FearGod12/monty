#include "monty.h"

/**
 * get_strtok - tokenizes a line
 * @line: line to be tokenised
 * @line_number: line number of the line to be tokenised
 * Return: token
 */
char *get_strtok(char *line, unsigned int line_number)
{
	char *delim = " ";
	char *token = NULL;
	char *arg = NULL;

	line = strtok(line, "\n"); /*removes newline*/
	token = strtok(line, delim);

	if (!token) /*ignore empty lines*/
		return (NULL);

	if (token[0] == '#') /*ignore comments*/
		return (NULL);

	arg = strtok(NULL, delim);
	if (arg && check_if_integer(arg)) /*if arguement !empty/!int*/
	{
		global_var = atoi(arg);
	}
	else if (arg == NULL && (strcmp(token, "push") == 0))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (token);
}
