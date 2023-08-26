#include "monty.h"
/**
 * _isdigit - checks if a string is all numerical
 * @str: string to check
 *
 * Return: 1 if true, 0 if false
 */
int _isdigit(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
