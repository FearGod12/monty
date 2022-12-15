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
	stack_t *top;
	stack_t	*temp = *stack;
	stack_t *second = *stack;

	(void) line_number;
	if (!stack || !(*stack))
	{
		return;
	}
	top = malloc(sizeof(stack_t));
	if (!top)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	top->n = second->n;
	top->next = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	top->prev = temp;
	temp->next = top;
	second = second->next;
	second->prev = NULL;
	temp = *stack;
	*stack = second;
	free(temp);
}
