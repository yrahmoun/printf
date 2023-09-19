#include "main.h"

/**
 * print_address - prints the address of a variable
 * @n: variable
 * @counter: counts characters printed
 */

void print_address(unsigned long n, int *counter)
{
	char base[] = "0123456789abcdef";

	if (n < 16)
		_putchar(base[n], counter);
	else
	{
		print_address((n / 16), counter);
		_putchar(base[n % 16], counter);
	}
}
