#include <stdlib.h>
#include "main.h"
/**
 * print_int - prints an integer
 * @num: the integer to be printed
 * @counter: counts characters printed
 */

void print_int(int num, int *counter)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		*counter += 11;
		return;
	}
	if (num < 0)
	{
		num *= -1;
		_putchar('-', counter);
	}
	if (num < 10)
	{
		_putchar(num + 48, counter);
	}
	else
	{
		print_int(num / 10, counter);
		_putchar(num % 10 + 48, counter);
	}
}
