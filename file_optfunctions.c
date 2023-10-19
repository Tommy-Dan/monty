#include "monty.h"

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
		format = parse_line(buff, line_number, format);
	}
	free(buff);
}
