#include "monty.h"


/**
 * get_opcode_func - Function to choose which opcode to execute
 *
 * @line: Line structure
 * @buffer: Bufffer Struct
 *
 * Return: Pointer to stack_t and unsigned int
 */
void (*get_opcode_func(file_l line, file_c * buffer))(stack_t **, unsigned int)
{
	unsigned int i;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (comment_check(line))
		return (nop);

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcodes[i].opcode, line.content[0]) == 0)
		{
			push_check(line, buffer, opcodes[i].opcode);

			if (arg.flag == 1 && strcmp(opcodes[i].opcode, "push") == 0)
			{
				if (line.content)
					free(line.content);
			}

			free(line.content);
			return (opcodes[i].f);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n",
						line.number, line.content[0]);
	free(line.content);
	free(buffer->buff);
	free_stack(&(buffer->stack));
	fclose(buffer->file);
	free(buffer);
	exit(EXIT_FAILURE);
}
