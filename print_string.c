#include "main.h"

/**
 * print_string - prints a string
 * @str: string to print
 * @counter: counts characters printed
 */

void print_string(char *str, int *counter)
{
	int i = 0;

	if (!str)
	{
		write(1, "(null)", 6);
		*counter += 6;
		return;
	}
	while (str[i])
	{
		_putchar(str[i], counter);
		i++;
	}
}
