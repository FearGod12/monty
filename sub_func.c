#include "monty.h"

/**
 * sub_func - subtracts the top element from the second
 * top element to store the result in the second stack
 * element so the stack is one element shorter.
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void sub_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0;

	(void) line_number;

	if (!stack || !(*stack) || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num += temp->n;
	temp = temp->next;
	num = temp->n - num;
	temp->n = num;
	*stack = temp;
}
