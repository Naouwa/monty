#include "monty.h"
/**
 * _swap - it swaps the top two elements of the stack
 * @head: the pointer to the top element
 * @line_num: the line number of the opcode
 */
void _swap(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->next;
	(*head)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *head;

	tmp->prev = NULL;
	tmp->next = *head;
	(*head)->prev = tmp;
	*head = tmp;
}

/**
 * _add - it adds the top two elements to the stack
 * @head: the head of the stack
 * @line_num: the line number
 */
void _add(stack_t **head, unsigned int line_num)
{
	stack_t *elem_1, *elem_2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	elem_1 = *head;
	elem_2 = (*head)->next;
	elem_2->n += elem_1->n;
	*head = elem_2;
	elem_2->prev = NULL;
	free(elem_1);
}
