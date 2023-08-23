#include "monty.h"
/**
 * push - opcode push pushes an element to the stack
 * @head: stack to push to
 * @line_num: line number of the opcode
 *
 */
void push(stack_t **head, unsigned int line_num)
{
	char *data = token2;

	if (isdigit(data) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exitstatus = EXIT_FAILURE;
	}
	if (newNode(head, atoi(data)) == NULL)
	{
		exitstatus = EXIT_FAILURE;
	}
}

/**
 * pall - it prints the stack
 * @head: the pointer to the head of the stack
 * @line_num: line number of opcode
 */
void pall(stack_t **head, unsigned int line_num)
{
	stack_t *h;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		(void)line_num;
	}
}
