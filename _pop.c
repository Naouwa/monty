#include "monty.h"
/**
 * _pop - it prints the top node of a stack
 * @head: the pointer to the first node
 * @line_num: the number of the opcode
 */
void _pop(stack_t **head, unsigned int line_num)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
