#include "monty.h"
#include <string.h>
#include <stdio.h>

/**
 * usgerror - prints usage error message and exits
 *
 */
void usgerror(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * _ferror - prints file error message and exits
 *
 * @filename: name of the file that could not be opened
 */
void _ferror(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * merror - prints malloc error message and exits
 *
 */
void merror(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

int exitstatus = 0;
char *token2 = NULL;

/**
 * main - interpreter program for Monty ByteCodes files
 * @argc: number of arguments
 * @argv: pointer to the arguments
 *
 * Return: nothing for now
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	char *token1, *buffer;
	stack_t *head = NULL;
	size_t bufflen = 256;
	unsigned int line_num = 1;

	if (argc != 2)
		usgerror();
	fptr = fopen(argv[1], "r");
	if (!fptr)
		_ferror(argv[1]);
	buffer = malloc(bufflen);
	if (buffer == NULL)
		merror();
	while (fgets(buffer, bufflen, fptr) != NULL)
	{
		if (exitstatus)
			break;
		if (*buffer == '\n')
		{
			line_num++;
			continue;
		}
		token1 = strtok(buffer, " \t\n");
		if (token1 == NULL)
		{
			line_num++;
			continue;
		}
		token2 = strtok(NULL, " \t\n");
		opfun(&head, token1, line_num);
		line_num++;
	}
	free(buffer);
	free_stack(head);
	fclose(fptr);
	exit(exitstatus);
}
