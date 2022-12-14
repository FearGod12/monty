#include "monty.h"

/**
 * pint_func - prints the top value of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}
