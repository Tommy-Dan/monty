#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>


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

//*Stack operations*/
stack_t *create_node(int n);
void free_nodes(struct_t *h);
void print_stack(stack_t **head, unsigned int buff);
void add_to_stack(stack_t **head, int m );
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln    );


/*file operations*/
void open_file(char *file_name);
int line_sept(char *buff, int line_number, int format);
void read_file(FILE *);
void func_called(op_func func, char *opc, char *value, int line_number, int format);
void find_function(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_stack(stack_t *head);
void print_stack(stack_t **head, unsigned int buff);
void add_to_stack(stack_t **head, int m);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **stack, unsigned int line_number);

/*Math operations with nodes*/
void stack_subtract(stack_t **stack, unsigned int line_number);
void stack_div(stack_t **stack, unsigned int line_number);
void stack_multiply(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);

/*String operations*/
void print_char(stack_t **stack, unsigned int line_number);
void printStr(stack_t **stack, __attribute__((unused))unsigned int line_n);
void r_fstNodr(stack_t **stack, __attribute__((unused))unsigned int line_n);
void r_lstNode(stack_t **stack, __attribute__((unused))unsigned int line_n

/*Error hanlding*/
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);

#endif
