#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * reverse_string - Function to reverse a string
 * @input: the string to be reversed
 * Return: returns the reversed string
 */
char *reverse_string(const char *input)
{
	int length = strlen(input);
	char *reversed = malloc(length + 1);
	int i;

	if (input == NULL)
		return (NULL);

	if (reversed == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
	{
		reversed[i] = input[length - 1 - i];
	}

	reversed[length] = '\0';

	return (reversed);
}
