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
		return (NULL);
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}
