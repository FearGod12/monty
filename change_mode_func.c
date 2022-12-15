#include "monty.h"

/**
 * change_mode_func - changes mode of operation to stack or queue.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 **/
void change_mode_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	if (!stack || (*stack))
		return;
	if (temp->prev == NULL && temp->next != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}
	else if (temp->prev != NULL && temp->next == NULL)
	{
		while (temp->prev != NULL)
			temp = temp->prev;
	}
	*stack = temp;
}
