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

	int num;
	if (!isdigit(data[0]) && data[0] != '-' && data[0] != '+')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exitstatus = EXIT_FAILURE;
		return;
	}

	num = atoi(data);
	{
		stack_t *newNode = malloc(sizeof(stack_t));
		if (newNode == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exitstatus = EXIT_FAILURE;
			return;
		}

		newNode->n = num;
		newNode->next = *head;
		newNode->prev = NULL;

		if (*head != NULL)
			(*head)->prev = newNode;

		*head = newNode;
	}
}

/**
 * pall - it prints the stack
 * @head: the pointer to the head of the stack
 * @line_num: line number of opcode
 */
void pall(stack_t **head, __attribute__((unused)) unsigned int line_num)
{
	printit(*head);
}
