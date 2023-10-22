#include "monty.h"


/**
 * f_add - adds to the top two elements of the stack
 * @head: the stack head
 * @line_n: the line number of the stack
 * Return: Return nothing
 */
void f_add(stack_t **head, unsigned int line_n)
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
		fprintf(stderr, "L%d: Can't add, stack too short\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
 * f_div - divides the top two elements of the stack
 * @head: the stack head
 * @line_n: the line number
 * Return: Return nothing
 */
void f_div(stack_t **head, unsigned int line_n)
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
		fprintf(stderr, "L%d: Can't divide, stack too short\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: diving by zero\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n / h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
 * f_mul - multiples the top two elements of the stack
 * @head: the stack head
 * @line_n: the line number of the stack
 * Return: Return nothing
 */
void f_mul(stack_t **head, unsigned int line_n)
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
		fprintf(stderr, "L%d: Can't multiply, stack too short\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->next->n * h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
 * f_sub - substract from two elements stack
 * @head: the head of the stack
 * @line_n: the line number
 * Return: Return nothing
 */
void f_sub(stack_t **head, unsigned int line_n)
{
	stack_t *temp;
	int diff;
	int nodes;

	temp = *head;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: Can't substract, stack too short\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	diff = temp->next->n - temp->n;
	temp->next->n = diff;
	*head = temp->next;
	free(temp);
}

/**
 * f_mod - compute and keep the remainder of the division
 * @head: the head of stak
 * @line_n: the line number
 * Return: Return nothing
 */
void f_mod(stack_t **head, unsigned int line_n)
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
		fprintf(stderr, "L%d: Can't mod, stack too short\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_n);
		fclose(m.file);
		free(m.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n % h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
