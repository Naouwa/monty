#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **head, unsigned int line_num);
} instruction_t;

#define FUNINSTRUCTION { \
	{"push", push}, \
	{"pall", pall}, \
	{"pint", _pint}, \
	{"pop", _pop}, \
	{"swap", _swap}, \
	{"add", _add}, \
	{"nop", _nop}, \
	{NULL, NULL} \
}

extern int exitstatus;
extern char *token2;


/* Functions */

int execute(char *buffer, stack_t **head, unsigned int line_num, FILE *fptr);
void opfun(stack_t **head, char *token, unsigned int line_num);
void push(stack_t **head, unsigned int line_num);
void pall(stack_t **head, unsigned int line_num);
void _add(stack_t **head, unsigned int line_num);
void _sub(stack_t **head, unsigned int line_num);
void _div(stack_t **head, unsigned int line_num);
void _mul(stack_t **head, unsigned int line_num);
void _mod(stack_t **head, unsigned int line_num);
stack_t *newNode(stack_t **head, int n);
void _pint(stack_t **head, unsigned int line_num);
void _pop(stack_t **head, unsigned int line_num);
void _nop(stack_t **head, unsigned int line_num);
void _swap(stack_t **head, unsigned int line_num);
void free_stack(stack_t *head);
char *_realloc(char *ptr, unsigned int prev_size, unsigned int actu_size);
size_t printit(const stack_t *head);
int _isdigit(char *str);
void usgerror(void);
void _ferror(char *filename);
void merror(void);

#endif /* _MONTY_H_ */
