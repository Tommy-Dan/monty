#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @head: head of the stack
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

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}


	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}

/**
 * print_stack - prints the stack
 * @head: stack head
 * @buff: no used
 * Return: no return
*/
void print_stack(stack_t **head, unsigned int buff)
{
	stack_t *tp;
	(void)buff;

	tp = *head;
	if (tp == NULL)
		return;

	while (tp)
	{
		printf("%d\n", tp->n);
		tp = tp->next;
	}
}

/**
 * add_to_stack - add node to the head stack
 * @head: head of the stack
 * @m: new_value
 * Return: no return
*/
void add_to_stack(stack_t **head, int m)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = create_node(m);

	if (temp)
	{
		temp->prev = new_node;
		new_node->n = n;
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
	}
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
