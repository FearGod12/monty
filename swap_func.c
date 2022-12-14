#include "monty.h"

/**
 * swap_func - swaps the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void swap_func(stack_t **stack, unsigned int line_number)
{
	stack_t *second, *first = *stack;
	int num;

	(void) line_number;

	if (!stack || !(*stack) || first->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second = first->next;

	num = first->n;
	first->n = second->n;
	second->n = num;
}
