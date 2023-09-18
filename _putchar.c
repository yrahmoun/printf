#include "main.h"

/**
 * _putchar - print a character
 * @c: character to print
 * @counter: counts characters printed
 */

void _putchar(char c, int *counter)
{
	write(1, &c, 1);
	*counter += 1;
}
