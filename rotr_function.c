#include "monty.h"

/**
 * rotr_func -  rotates the stack to the top.
 * The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void rotr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	int val = 0, index = list_len(*stack) - 1;
	(void) line_number;

	if (!*stack || !(*stack)->next)
		return;
	last = get_dnodeint_at_index(*stack, index);
	val = last->n;
	delete_dnodeint_at_index(stack, index);
	add_dnodeint(stack, val);
	
}
