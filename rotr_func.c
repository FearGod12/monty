#include "monty.h"

/**
 * rotl_func - rotates elements of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void rotl_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top = *stack;

	(void) line_number;
	*stack = top->next;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = top;
	top->next = NULL;
}
