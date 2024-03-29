#include "monty.h"

arg_t arg = {0, 0};

/**
 * free_stack - frees all nodes in a stack.
 * @stack: pointer to head node pointer of a stack.
 *
 * Return: NAIN
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}


/**
 * push_check - check if push opcode is being used and sets
 * global argument variable if true.
 * @line: struct containg line content and number.
 * @opcode: opcode to compare.
 * @meta: struct containing all alocated memory.
 *
 * Return: NAIN.
 */
void push_check(file_l line, file_c *buffer, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) &&  !argument_check(line.content[1]))
	{
		free(line.content);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		free(buffer->buff);
		free_stack(&(buffer->stack));
		fclose(buffer->file);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		arg.arg = atoi(line.content[1]);
}


/**
 * argument_check - checks arg validity.
 * @token: argument to be checked.
 *
 * Return: true if valid otherwise false.
 */
bool argument_check(char *token)
{
	unsigned int i;
	
	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		
		if (token[i] < '0' || token[i] > '9')
			return (false);
												}

	return (true);
}

