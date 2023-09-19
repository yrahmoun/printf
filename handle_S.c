#include "main.h"

/**
 * handle_S - handles custom specifier for non printable
 * characters
 * @s: string to print
 * @counter: counts characters printed
 */

void handle_S(char *s, int *counter)
{
	int i = 0;
	char base[] = "0123456789ABCDEF";

	while (s[i])
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			print_string("\\x0", counter);
			print_hex((unsigned int)s[i], base, counter);
		}
		else
			_putchar(s[i], counter);
		i++;
	}
}
