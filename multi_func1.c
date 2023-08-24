#include "monty.h"
/**
 * _sub - subtracts the top element of the stack from the second top
 * @head: the pointer to the head of the stack
 * @line_num: the line number of the opcode
 */
void _sub(stack_t **head, unsigned int line_num)
{
	stack_t *elem_1, *elem_2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	elem_1 = *head;
	elem_2 = (*head)->next;
	elem_2->n -= elem_1->n;
	*head = elem_2;
	elem_2->prev = NULL;
	free(elem_1);
}

/**
 * _div - divides the second top element of the stack by the top
 * @head : the pointer to the head of the stack
 * @line_num: the line number of the opcode
 */
void _div(stack_t **head, unsigned int line_num)
{
	int division = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		division = (*head)->n;
		_pop(head, line_num);
		(*head)->n /= division;
	}
}

/**
 * _mul - multiplies the second top element of the stack with the top
 * @head : the pointer to the head of the stack
 * @line_num: the line number of the opcode
 */
void _mul(stack_t **head, unsigned int line_num)
{
	int multip;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		multip = (*head)->n;
		_pop(head, line_num);
		(*head)->n *= multip;
	}
}

/**
 * _mod - computes the rest of the division of the second top
 * @head : the pointer to the head of the stack
 * @line_num: the line number of the opcode
 */
void _mod(stack_t **head, unsigned int line_num)
{
	int modul = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		modul = (*head)->n;
		_pop(head, line_num);
		(*head)->n %= modul;
	}
}
