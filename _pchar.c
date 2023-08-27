#include "monty.h"
/**
 * pchar - it prints the char at the top of the stack
 * @head: the pointer to the head of the stack
 * @line_num: the line number
 */
void pchar(stack_t **head, unsigned int line_num)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", h->n);
}
