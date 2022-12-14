#include "monty.h"

/**
 * add_func - adds the top two elements together
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0;

	(void) line_number;

	if (!stack || !(*stack) || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num += temp->n;
	temp = temp->next;
	num += temp->n;
	temp->n = num;
	*stack = temp;
}
