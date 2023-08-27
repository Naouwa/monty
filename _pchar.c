#include "monty.h"
/**
 * _pchar - it prints the char at the top of the stack
 * @head: the pointer to the head of the stack
 * @line_num: the line number
 */
void _pchar(stack_t **head, unsigned int line_num)
{
	if (head == '\0' || head[0] == '\0')
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

		if (head[0]->n < 32 || head[0]->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", head[0]->n);
}
