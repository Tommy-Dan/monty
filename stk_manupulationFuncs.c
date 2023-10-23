#include "monty.h"

/**
 * top_rotate - rotate stack to the top
 * @head: the stack head
 * @line_n: line_n
 * Return: Return nothing
 */
void top_rotate(stack_t **head, __attribute__((unused)) unsigned int line_n)
{
	stack_t *current = *head, *temp;

	if (*head == NULL || (*head)->next == NULL)
		return;
	temp = (*head)->next;
	temp->prev = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = *head;
	(*head)->next = NULL;
	(*head)->prev = current;
	(*head) = temp;
}


/**
 * bottom_rotate - rotate stack to the bottom
 * @head: the stack head
 * @line_n: the line number of the stack
 * Return: Return nothing
 */
void bottom_rotate(stack_t **head, __attribute__((unused)) unsigned int line_n)
{
	stack_t *cpy;

	cpy = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = *head;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*head) = cpy;
}

/**
 * f_nop - printing nothing
 * @head: the stack head
 * @line_n: the line number
 * Return: Return nothing
 */
void f_nop(stack_t **head, unsigned int line_n)
{
	(void)head;
	(void)line_n;
}

/**
 * free_stack - free the double linked list
 * @head: the head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
