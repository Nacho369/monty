#include "monty.h"


/**
 * mod_opcode - Finds modulus of top 2 elements and stores it in 2nd element.
 *
 * @stack: pointer to the head node pointer of stack
 * @line_num line number
 *
 * Return: void
 */
void mod_opcode(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
