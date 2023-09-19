#include "main.h"

/**
 * print_address - prints the address of a variable
 * @n: variable to print it's adress
 * @counter: counts characters printed
 */

void print_address(unsigned long n, int *counter)
{
	char base[] = "0123456789abcdef";
	char address[16];
	int i = 0;

	if (!n)
	{
		print_string("(nil)", counter);
		return;
	}
	print_string("0x", counter);
	while (n > 0)
	{
		address[i] = base[n % 16];
		n /= 16;
		i++;
	}
	for (i = i - 1; i >= 0; i--)
		_putchar(address[i], counter);
}
