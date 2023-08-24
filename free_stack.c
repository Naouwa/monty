#include "monty.h"

/**
 * free_stack - it frees the stack_t list
 * @head: the first node of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *current, *next;

	current = head;
	if (head)
	{
		next = head->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
