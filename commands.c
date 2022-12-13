#include "monty.h"

/**
 * push_func - adds new data to the stack
 * @stack: pointer to the top of stack
 * @n: new data to be added
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
	return;
}
/**
 * pall_func - prints all the values on the stack
 * @stack - pointer to the top of the stack
 * @line_number - line number of code from file read
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;
	if (!stack || !(*stack))
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return;
}
