#include "monty.h"

/**
 * mul_func - muliplies the second top element of the
 * stack with the first element, stack is one element
 * shorter on success.
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void mul_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0;

	(void) line_number;

	if (!stack || !(*stack) || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = temp->n;
	temp = temp->next;
	temp->n = temp->n * num;
	*stack = temp;
}
