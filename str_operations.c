#include "monty.h"

/**
 * print_char - prints character.
 * @stack: pointer pointing to top node of the stack.
 * @line_number: the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "can't pchar, stack empty\n");
		exit(EXIT_FAILURE);
	}

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
	{
		fprintf(stderr, "can't pchar, value out of range\n");
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ascii);
}

/**
 * printStr - prints string
 * @stack: pointer pointing to top node of the stack
 * @line_n: the line number
 */
void printStr(stack_t **stack, __attribute__((unused))unsigned int line_n)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * r_fstNode - rotates first node of the stack to bottom
 * @stack: pointer pointing to top node of the stack.
 * @line_n: the line number of of the opcode.
 */
void r_fstNode(stack_t **stack, __attribute__((unused))unsigned int line_n)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * r_lstNode - rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_n: the line number of of the opcode.
 */
void r_lstNode(stack_t **stack, __attribute__((unused))unsigned int line_n)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
