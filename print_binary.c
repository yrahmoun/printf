#include "main.h"
/**
 * print_binary - Function that handles custom b conversion specifier
 * @num: the integer to be printed in binary
 * @counter: counts characters printed
 */

void print_binary(unsigned int num, int *counter)
{
	int binary[32];
	int index = 0;
	int i;

	if (num == 0)
	{
		_putchar('0', counter);
		return;
	}
	while (num > 0)
	{
		binary[index++] = num % 2;
		num /= 2;
	}
	for (i = index - 1; i >= 0; i--)
		_putchar('0' + binary[i], counter);
}
