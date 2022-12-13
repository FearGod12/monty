#include "monty.h"

/**
 * check_if_integer - checks if a string contains a number
 * @arg: string to be checked
 * Return: 1 if true or 0 if false
 */
int check_if_integer(char *arg)
{
	int i = 0;

	while (*(arg + 1) != '\0')
	{
		if (*(arg + 1) >= '0' && *(arg + 1) <= '9')
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
