#include "monty.h"


/**
 * push - pushes node to top of stack.
 *
 * @stack: pointer to head node pointer of stack
 * @line_num: line number.
 *
 * Return: NAIN.
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp->next = *stack;
	temp->prev = NULL;
	temp->n = arg.arg;
	if (*stack)
		(*stack)->prev = temp;
	*stack = temp;
}


/**
 * pall - prints data of all nodes in stack.
 *
 * @stack: pointer to head node pointer of stack.
 * @line_num: line number.
 *
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	(void)line_num;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * nop - does NAIN.
 * @stack: pointer to head node pointer of stack.
 * @line_num: line number.
 *
 * Return: NAIN.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
