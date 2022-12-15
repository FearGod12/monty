#include "monty.h"

/**
 * free_dlistint - frees a doubly linked list
 * @head: head pointer to the list
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
