#include "main.h"
#include <ctype.h>
/**
 * print_rot13 - Function to ncode and print a string in the ROT13 algorithm.
 * @str: The string to be encoded and printed.
 * @counter: Counts characters printed.
 */

void print_rot13(const char *str, int *counter)
{
	int i;

	if (str == NULL)
	{
		return;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		char c = str[i];

		if (isalpha(c))
		{
			char base = isupper(c) ? 'A' : 'a';
			char rotated = ((c - base + 13) % 26) + base;

			_putchar(rotated, counter);
		}
		else
		{
			_putchar(c, counter);
		}
	}
}
