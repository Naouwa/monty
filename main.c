#include "monty.h"
#include <string.h>
#include <stdio.h>

/* This is where argument for opcode will be stored */
char *token2 = NULL;

/* Exit status that will be updated in functions outside of main */
int exitstatus = 0;

/**
 * main - interpreter program for Monty ByteCodes files
 * @argc: number of arguments
 * @argv: pointer to the arguments
 *
 * Return: nothing for now
 */
int main(int argc, char **argv)
{
	FILE *fptr;
	char *token1, *buffer;
	stack_t *stack = NULL;
	size_t bufflen = 256;
	unsigned int lnum = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(bufflen);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, bufflen, fptr) != NULL)
	{
		if (*buffer == '\n')
		{
			lnum++;
			continue;
		}
		token1 = strtok(buffer, " \t\n");
		if (token1 == NULL)
		{
			lnum++;
			continue;
		}
		token2 = strtok(NULL, " \t\n");
		opfun(&stack, token1, lnum);
		lnum++;
	}
	free(buffer);
	fclose(fptr);
	exit(exitstatus);
}
