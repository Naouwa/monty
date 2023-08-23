#include "monty.h"
#include <ctype.h>
/**
 * push - opcode push pushes an element to the stack
 * @stack: stack to push to
 * @lnum: line number of the opcode
 *
 */
void push(stack_t **stack, unsigned int lnum)
{
	char *data = token2;

	if (isdigit(data) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer", lnum);
		exitstatus = EXIT_FAILURE;
		return;
	}
	if (newNode(stack, atoi(data)) == NULL)
	{
		exitstatus = EXIT_FAILURE;
		return;
	}
}
