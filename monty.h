#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/types.h>

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

/**
 * struct monty_t - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @stackMode: flag to change stack queue
 * Description: carries values through the program
 */
typedef struct monty_t
{
	char *arg;
	FILE *file;
	char *content;
	int stackMode;
} monty_t;
extern monty_t m;


ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
/*===string operations===*/
void printChar(stack_t **head, unsigned int line_n);
void print_topchar(stack_t **head, unsigned int line_n);
void print_string(stack_t **head, unsigned int line_n);
void print_sktop(stack_t **head, unsigned int line_n);

/*===stack operations===*/
void f_pint(stack_t **head, unsigned int line_n);
void f_pop(stack_t **head, unsigned int line_n);
void f_push(stack_t **head, unsigned int line_n);
void f_pall(stack_t **head, unsigned int line_n);
void f_stack(stack_t **head, unsigned int line_n);

/*===stack manupulations===*/
void top_rotate(stack_t **head, __attribute__((unused)) unsigned int line_n);
void bottom_rotate(stack_t **head, __attribute__((unused)) unsigned int line_n);
void f_nop(stack_t **head, unsigned int line_n);
void free_stack(stack_t *head);

/*===maths operations===*/
void f_add(stack_t **head, unsigned int line_n);
void f_div(stack_t **head, unsigned int line_n);
void f_mul(stack_t **head, unsigned int line_n);
void f_sub(stack_t **head, unsigned int line_n);
void f_mod(stack_t **head, unsigned int line_n);

/*===nodes operations===*/
void add_node(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int line_n);
void add_queue(stack_t **head, int n);
void f_swap(stack_t **head, unsigned int line_n);
int executable(char *content, stack_t **stack, unsigned int line_n, FILE *file);


#endif
