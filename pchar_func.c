#include "monty.h"

/**
 * pchar_func - prints the top value of the stack
 * as a ASCII char
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void pchar_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n < 32 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(temp->n);
	putchar('\n');
}
