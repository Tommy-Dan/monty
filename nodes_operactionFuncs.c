#include "monty.h"


/**
 * add_node - add nodes to the head of the stack
 * @head: the head of the stack
 * @n: new value
 * Return: Return nothing
 */
void add_node(stack_t **head, int n)
{
	stack_t *new_node;
	stack_t *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}


/**
 * f_queue - prints the top of a queue
 * @head: the queue head
 * @line_n: the line number
 * Return: Return nothing
 */
void f_queue(stack_t **head, unsigned int line_n)
{
	(void)head;
	(void)line_n;
	m.stackMode = 1;
}

/**
 * add_queue - add node to the tail of the queue
 * @head: the head of the queue
 * @n: new value
 * Return: Return nothing
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n");
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}

/**
 * f_swap - adds elements to the top of the stack
 * @head: the stack head
 * @line_n: the line number
 * Return: Return nothing
 */
void f_swap(stack_t **head, unsigned int line_n)
{
	stack_t *h;
	int temp;
	int length = 0;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: Can't swap, stack too short\n", length);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = line_n;
}

/**
 * executable - execute the opecode
 * @stack: the head linked list stack
 * @line_n: the number of lines
 * @file: pointer pointing tp the monty file
 * @content: the content of the line
 * Return: Return nothing
 */
int executable(char *content, stack_t **stack, unsigned int line_n, FILE *file)
{
	instruction_t open_stack[] = {
		{"push", f_push}, {"pall", f_pall},
		{"pint", f_pint}, {"pop", f_pop},
		{"add", f_add}, {"nop", f_nop},
		{"sub", f_sub}, {"div", f_div},
		{"mul", f_mul}, {"mod", f_mod},
		{"swap", f_swap}, {"pchar", printChar},
		{"pstr", printString}, {"queue", f_queue},
		{"stack", f_stack}, {"rotl", top_rotate},
		{"rotr", bottom_rotate},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opr;

	opr = strtok(content, " \n\t");
	if (opr && opt[0] == '#')
		return (0);
	m.arg = strtok(NULL, " \n\t");
	while (open_stack[i].opcode && opr)
	{
		if (strcmp(opr, open_stack[i].opcode) == 0)
		{
			open_stack[i].f(stack, line_n);
			return (0);
		}
		i++;
	}
	if (opr && open_stack[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opr);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
