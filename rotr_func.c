#include "monty.h"

/**
 * rotr_func - rotates the stack to the bottom.
 * The last element of the stack becomes the top element of the stack
 * @stack: pointer to the head
 * @line_number: line number where the opcode was read from file
 */
void rotr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *top = *stack;

	(void) line_number;
	if (!stack || !(*stack))
		return;
	*stack = temp->next;
	while (temp->next->next != NULL)
	{
		*stack = (*stack)->next;
		temp = temp->next;
	}
	(*stack)->next = top;
	temp->next = NULL;
}
