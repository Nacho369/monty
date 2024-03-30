#include "monty.h"


/**
 * swap - Swap the twp top elements of the stack
 *
 * @stack: Pointer to the head of the list
 * @line_num: Line number in the file
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *count;
	unsigned int i, temp, len = 0;

	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	count = *stack;

	for (i = 0; count; i++)
	{
		len++;
		count = count->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}


/**
 * add_opcode - finds sum of top two elements
 *
 * @stack: pointer to the head node pointer of stack
 * @line_num: line number
 *
 * Return: NAIN
 */
void add_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}


/**
 * sub_opcode - finds sum of top two elements
 *
 * @stack: pointer to the head node pointer of stack
 * @line_num: line number
 * Return: NAIN
 */
void sub_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
