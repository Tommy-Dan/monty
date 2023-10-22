#include "monty.h"

/**
 * printChar - prints character at the top of the stack
 * @head: pointer pointing to the head of the stack
 * @line_n: line number where the function is called
 * Return: Return nothing
 */
void printChar(stack_t **head, unsigned int line_n)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d:  can't pint, stack value out of range\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}


/**
 * print_topchar - print the character at the top of stack.
 * @head: pointer pointing to the head of stack
 * @line_n: the line number in the function
 * Return: Return nothing
 */
void print_topchar(stack_t **head, unsigned int line_n)
{
	stack_t *h;

	h = *head;

	if (!h)
	{
		fprintf(stderr, "L%d: Can't print character, stack empty\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: Can't print character, stack out of range", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * print_string - print the string starting at the top of stack
 * @head: the head of the stack
 * @line_n: the line number
 * Return: Return nothing
 */
void print_string(stack_t **head, unsigned int line_n)
{
	stack_t *h;
	(void)line_n;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}


/**
 * print_sktop - print the top stack
 * @head: the head of the stack
 * @line_n: the line number in the function
 * Return: Return nothing
 */
void print_sktop(stack_t **head, unsigned int line_n)
{
	(void)head;
	(void)line_n;
	m.stackMode = 0;
}
