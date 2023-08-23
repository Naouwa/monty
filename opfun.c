#include "monty.h"
#include <string.h>
/*
 * opfun - runs the builtin like push, pall etc...
 * @stack: the stack subject to the opcode
 * @token: first token of the opcode line
 * @lnum: line number starting from 1
 *
 */
void opfun(stack_t **stack, char *token, unsigned int lnum)
{
	int i = 0;
	instruction_t op[] = FUNINSTRUCTION;

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, token) == 0)
		{
			op[i].f(stack, lnum);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lnum, token);
	exit(EXIT_FAILURE);
}
