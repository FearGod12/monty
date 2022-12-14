#include "monty.h"

/**
 * pall_func - prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pall, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
