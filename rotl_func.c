#include "monty.h"

/**
<<<<<<< HEAD
 * rotl_func - rotates elements of a stack
=======
 * rotl_func -  rotates the stack to the top.
 * The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
>>>>>>> 89eaec8cf4a9b90d371e7a26e554d7aa770f273b
 * @stack: pointer to the top of the stack
 * @line_number: line number of code from file read
 */
void rotl_func(stack_t **stack, unsigned int line_number)
{
<<<<<<< HEAD
	stack_t *temp, *top = *stack;

	(void) line_number;
	*stack = top->next;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = top;
	top->next = NULL;
=======
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
>>>>>>> 89eaec8cf4a9b90d371e7a26e554d7aa770f273b
}
