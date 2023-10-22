#include "monty.h"


/**
 * f_pint - print the top
 * @head: the stack head
 * @line_n: the line number
 * Return: Return nothing
 */
void f_pint(stack_t **head, unsigned int line_n)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: Can't pint, stack empty\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


/**
 * f_pop - print the top element
 * @head: the stack head
 * @line_n: the line number of function
 * Return: Return nothing
 */
void f_pop(stack_t **head, unsigned in line_n)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: Can't pop an empty stack\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
 * f_push - add node to the stack
 * @head: the head of the stack
 * @line_n: the line number of the file
 * Return: Return nothing
 */
void f_push(stack_t **head, unsigned int line_n)
{
	int n;
	int i = 0;
	int flag = 0;

	if (m.arg)
	{
		if (m.arg[0] == '-')
			i++;
		for (; m.arg[i] != '\0'; i++)
		{
			if (m.arg[i] > 57 || m.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			fclose(m.file);
			free(m.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(m.arg);
	if (m.stackMode == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}

/**
 * f_pall - print the stack
 * @head: the head of the stack
 * @line_n: the line of the function line
 * Return: Return nothing
 */
void f_pall(stack_t **head, unsigned int line_n)
{
	stack_t *h;
	(void)line_n;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * f_stack - print the top stack
 * @head: the head stack
 * @line_n: the line number
 * Return: Return nothing
 */
void f_stack(stack_t **head, unsigned int line_n)
{
	(void)head;
	(void)line_n;
	m.stackMode = 0;
}
