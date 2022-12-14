#include "monty.h"

/**
 * div_func - divides the second element of the stack
 * by the top element to store the result in the second stack
 * element so the stack is one element shorter.
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void div_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0;

	(void) line_number;

	if (!stack || !(*stack) || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = temp->n;
	temp = temp->next;
	temp->n = temp->n / num;
	*stack = temp;
}
