#include "monty.h"

/**
 * pstr_func - print string from top of the stack
 * as a ASCII char and stops if value is 0, NULL
 * or out of range.
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void pstr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp != NULL)
	{
		if (temp->n != 0)
		{
			if (temp->n >= 32 && temp->n <= 127)
				putchar(temp->n);
		}
		else
		{
			break;
		}
		temp = temp->next;
	}
	putchar('\n');
}
