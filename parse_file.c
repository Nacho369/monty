#include "monty.h"


/**
 * parsefile - reads and parses file line by line.
 * @file: script to be read.
 *
 * Return: nothing.
 */
void parse_file(FILE *file)
{
	file_c *buffer = NULL;
	file_l line;
	size_t len = 0;

	buffer = malloc(sizeof(file_c));
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	line.number = 0;
	line.content = NULL;

	buffer->file = file;
	buffer->stack = NULL;
	buffer->buff = NULL;

	while (getline(&(buffer->buff), &len, buffer->file) != -1)
	{
		line.number++;
		parseline(&line, buffer->buff);

		if (line.content != NULL)
			get_opcode_func(line, buffer)(&(buffer->stack), line.number);
	}

	free(buffer->buff);
	free_stack(&(buffer->stack));
	fclose(buffer->file);
	free(buffer);
}


/**
 * parseline - parses then tokenizes a line of text storing
 * it in a line struct.
 * @line: struct containing content and line number.
 * @buffer: string of text read from script file.
 *
 * Return: nothing
 */
void parseline(file_l *line, char *buffer)
{
	unsigned int i;
	char *token = NULL;

	line->content = malloc(sizeof(char *) * 3);
	if (!line->content)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, " '\n'");
	for (i = 0; token && i < 2; i++)
	{
		line->content[i] = token;
		token = strtok(NULL, " \n");
	}

	line->content[i] = NULL;
}

