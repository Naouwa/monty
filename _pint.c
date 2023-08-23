#include "monty.h"
/**
 * _pint - it prints an integer on top of the stack
 * @head: a pointer to the stack linked list
 * @line_num: the number of instruction
 */
void _pint(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
