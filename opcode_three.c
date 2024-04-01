#include "monty.h"


/**
 * mod_opcode - Finds modulus of top 2 elements and stores it in 2nd element.
 *
 * @stack: pointer to the head node pointer of stack
 * @line_num: line number
 *
 * Return: void
 */
void mod_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}


/**
 * pchar - Prints the char at the top of the stack, followed by a new line
 *
 * @stack: Pointer to the head node pointer of stack
 * @line_num: Line number
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	int val;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;

	if (val < 0 || val > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)val);
}


/**
 * pstr - Prints the string starting at the top of the stack,
 * followed by a new line
 *
 * @stack: Pointer to the head node pointer of stack
 * @line_num: Line number
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	unsigned int i;
	stack_t *temp;
	(void)line_num;

	temp = *stack;

	for (i = 0; temp; i++)
	{
		if (temp->n > 127 || temp->n <= 0)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}


/**
 * rotl - Rotates the stack to the top.
 *
 * @stack: Pointer to the head node of the stack
 * @line_num: Line number
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *last_node, *current;
	(void)line_num;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next)
		temp = temp->next;

	current = *stack;
	last_node = temp;
	last_node->next = current;
	current->prev = last_node;
	*stack = current->next;
	current->next->prev = NULL;
	current->next = NULL;
}


/**
 * rotr - Rotates the stack to the bottom
 *
 * @stack: Pointer to the head node of the stack
 * @line_num: Line Number
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *top_node;
	(void)line_num;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next)
		temp = temp->next;

	top_node = temp;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = top_node;
	top_node->prev->next = NULL;
	top_node->prev = NULL;
}
