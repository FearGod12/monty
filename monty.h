#ifndef _MONTY_H
#define _MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>
#include <fcntl.h>

extern int global_var;
int global_var;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);
void add_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);
void sub_func(stack_t **stack, unsigned int line_number);
void div_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);
void mod_func(stack_t **stack, unsigned int line_number);
void pchar_func(stack_t **stack, unsigned int line_number);
void pstr_func(stack_t **stack, unsigned int line_number);
void rotl_func(stack_t **stack, unsigned int line_number);
void rotr_func(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void change_mode_func(stack_t **stack, unsigned int line_number);

void get_command(char *token, stack_t **head, unsigned int line_number);
char *get_strtok(char *line, unsigned int line_number);
int check_if_integer(char *arg);



#endif
