#include "monty.h"
/**
 * newNode - adds new node to the start of stack
 * @head: start of stack
 * @n: element to add to new node
 *
 * Return: pointer to new node or NULL if fail
 */
stack_t *newNode(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * printit - prints elements of a stack
 * @head: head of stack
 *
 * Return: nu;ber of elements printed
 */
size_t printit(const stack_t *head)
{
	size_t i = 0;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		i++;
	}
	return (i);
}
