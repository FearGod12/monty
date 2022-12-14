#include "monty.h"

/**
 * pop_func - pops or remover the element at the top
 * of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = temp->next;
	free(temp);
}
