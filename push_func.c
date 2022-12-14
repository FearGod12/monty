#include "monty.h"

/**
 * push_func - adds new data to the stack
 * @stack: pointer to the top of stack
 * @line_number: line number
 * Return: nothing
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp = *stack;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = global_var;
	new->prev = NULL;
	if (!stack)
	{
		new->next = NULL;
		*stack = new;
		return;
	}
	new->next = temp;
	temp->prev = new;
}
