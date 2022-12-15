#include "monty.h"

/**
 * get_dnodeint_at_index - gets the nth node of a doubly linked list
 * @head: head pointer to the list
 * @index: index of the node to return
 *
 * Return: address of the node, or if it does not exist, NULL
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head)
	{
		if (index == i)
			return (head);
		head = head->next;
		i++;
	}

	return (NULL);
}

/**
 * list_len - returns the number of elements
 * in a doubly linked list
 * @h: head pointer to the list
 *
 * Return: number of elements
 */
size_t list_len(const stack_t *h)
{
	size_t i = 0;

	while (h)
	{
		i++;
		h = h->next;
	}

	return (i);
}

/**
 * add_dnodeint - adds a new node at the
 * beginning of a doubly linked list
 * @head: head double pointer to the list
 * @n: int data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;

	if (!(*head))
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
		return (new);
	}

	new->next = *head;
	new->prev = NULL;
	(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end
 * of a doubly linked list
 * @head: head double pointer to the list
 * @n: int data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *last = *head;
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (!(*head))
	{
		*head = new;
		new->prev = NULL;
		return (new);
	}

	while (last->next)
		last = last->next;

	last->next = new;
	new->prev = last;

	return (*head);
}
/**
 * delete_dnodeint_at_index - deletes a node in a doubly linked list
 * at a given index
 * @head: head double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp = *head;
	unsigned int i = 0;

	if (!(*head))
		return (-1);

	while (temp && i != index)
	{
		i++;
		temp = temp->next;
	}

	if (!temp)
		return (-1);
	else if (temp == *head)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(temp);
	}
	else if (temp->next == NULL)
	{
		temp->prev->next = NULL;
		free(temp);
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}

	return (1);
}
