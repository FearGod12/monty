#include "monty.h"

/**
 * rotl_func -  rotates the stack to the top.
 * The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void rotl_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *top = *stack;

	(void) line_number;
	if (!stack || !(*stack) || temp->next == NULL)
	{
		return;
	}
	*stack = top->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = top;
	/*temp->prev->next = NULL;*/
	top->next = NULL;
}
