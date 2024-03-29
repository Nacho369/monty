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
 * pint - Prints the value at the top of the stack, followed by a new line
 *
 * @stack: Pointer to the head node pointer of stack
 * @line_num: Line number of file
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	unsigned int i;

	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	for (i = 0; temp; i++)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->next;
	}

	printf("%d\n", temp->n);
}


/**
 * pop - Pops the top element of the stack
 *
 * @stack: Pointer to the head node pointer of stack
 * @line_num: Line number of file
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}

}


/**
 * nop - does NAIN.
 *
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
