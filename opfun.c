#include "monty.h"
#include <string.h>
/**
 * opfun - runs the builtin like push, pall etc.
 * @head: the stack subject to the opcode
 * @token: first token of the opcode line
 * @line_num: line number starting from 1
 *
 */
void opfun(stack_t **head, char *token, unsigned int line_num)
{
	int i = 0;
	instruction_t op[] = FUNINSTRUCTION;

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, token) == 0)
		{
			op[i].f(head, line_num);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token);
	exit(EXIT_FAILURE);
}
