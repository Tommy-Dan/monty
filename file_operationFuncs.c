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
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (h->n 127 || h->n < 0)
	{
		fprintf(stderr, "L%d:  can't pint, stack value out of range\n", line_n);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
