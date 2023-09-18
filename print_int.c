#include <stdlib.h>
#include "main.h"
/**
 * print_int - prints an integer
 * @num: the integer to be printed
 * @counter: counts characters printed
 */

void print_int(int num, int *counter)
{
	int is_negative;
	int index;
	char *digits;

	if (num == 0)
	{
		_putchar('0', counter);
		return;
	}

	is_negative = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	digits = (char *)malloc(12);
	{
		return;
	}

	index = 0;
	while (num > 0)
	{
		digits[index++] = (num % 10) + '0';
		num /= 10;
	}

	if (is_negative)
	{
		digits[index++] = '-';
	}

	while (index > 0)
	{
		_putchar(digits[--index], counter);
	}

	free(digits);
}

