#include "monty.h"


monty_t m = {NULL, NULL, NULL, 0};
/**
 * main - entry point of monty code interpreter
 * @argc: number of arguments
 * @argv: argument vector monty file
 * Return: Return(0) on success
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	m.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		m.content = content;
		line_n++;
		if (read_line > 0)
			executable(content, &stack, line_n, file);
		free(content);
	}
	free_stack(stack);
	fclose(file);

	return (0);
}
