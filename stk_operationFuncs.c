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
