#include "monty.h"

stack_t *stack = NULL;

/**
 * free_stack - it frees the stack_t list
 * @head: the first node of the stack
 */
void free_stack(stack_t *head)
{
	while (head)
	{
		stack_t *tmp = head;
		head = head->next;
		free(tmp);
	}
}
