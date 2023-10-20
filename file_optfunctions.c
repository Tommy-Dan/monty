#include "monty.h"



/**
 * line_sept - Separates each line into tokens
 * @buff: line from the file
 * @line_number: the line number
 * @format:  the storage format,if 0 node will be entered as a stack
 * otherwis node will be entered as a queue.
 * Return: Returns (0) if the opcode is stack, otherwise 1 for queue.
 */

int line_sept(char *buff, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}

/**
 * open_file - opens a file
 * @file_name: the file namepath
 * Return: void
 */
void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	read_file(fd);
	fclose(fd);
}

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buff = NULL;
	size_t length = 0;

	for (line_number = 1; getline(&buff, &length, fd) != -1; line_number++)
	{
		format = line_sept(buff, line_number, format);
	}
	free(buff);
}

/**
 * func_called - Calls the required function
 * @func: pointer pointing to the function to be called
 * @opc: string representing the opcode
 * @value: string representing a numeric value
 * @line_number: the line numeber
 * @format: the format, if 0 Nodes entered as a stack
 * otherwise entered as a queue.
 */

void func_called(op_func func,
		char *opc,
		char *value,
		int line_number,
		int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

/**
 * find_function - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: the argument of opcode
 * @format: the  storage format, if 0 nodes entered stack otherwise queue
 * @line_number: the line number
 * Return: void
 */
void find_function(char *opcode, char *value, int line_number, int format)
{
	int i;
	int flag;

	instruction_t function_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; function_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, function_list[i].opcode) == 0)
		{
			call_fun(function_list[i].f, opcode, value, line_number, format);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n");
		exit(EXIT_FAILURE);
	}
}
