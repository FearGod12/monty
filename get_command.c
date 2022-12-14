#include "monty.h"

/**
 * get_command - matches a token to a command
 * @token: token to be matched
 * @head: pointer to the top of the stack
 * @line_number: lune number
 */
void get_command(char *token, stack_t **head, unsigned int line_number)
{
	instruction_t cmd[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{"pchar", pchar_func},
		{NULL, NULL}
	};
	int index = 0;

	while (cmd[index].opcode != NULL)
	{
		if (strcmp(token, cmd[index].opcode) == 0)
		{
			cmd[index].f(head, line_number);
			return;
		}
		index++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}
