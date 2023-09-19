#include "main.h"

/**
 * print_uns - prints unsigned number
 * @n: number to print
 * @counter: counts characters
 */

void print_uns(unsigned int n, int *counter)
{
	if (n < 10)
		_putchar(n + 48, counter);
	else
	{
		print_uns(n / 10, counter);
		_putchar(n % 10 + 48, counter);
	}
}

/**
 * print_octal - prints octal number
 * @n: number to print
 * @counter: counts characters printed
 */

void print_octal(unsigned int n, int *counter)
{
	char octal[100];
	int i = 0;

	if (!n)
	{
		_putchar('0', counter);
		return;
	}
	while (n > 0)
	{
		octal[i] = n % 8;
		n /= 8;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		_putchar(octal[j] + 48, counter);
}

/**
 * print_hex - prints number in hexadecimal
 * @n: number to print
 * @base: string holding hexadecimal characters
 * @counter: counts characters printed
 */

void print_hex(unsigned int n, char *base, int *counter)
{
	if (n < 16)
		_putchar(base[n], counter);
	else
	{
		print_hex((n / 16), base, counter);
		_putchar(base[n % 16], counter);
	}
}

/**
 * handle_uoxX - handles cases %u %o %x %X
 * @c: specifier
 * @list: list of arguments
 * @counter: counts characters printed
 */

void handle_uoxX(char c, va_list list, int *counter)
{
	if (c == 'u')
		print_uns(va_arg(list, unsigned int), counter);
	else if (c == 'o')
		print_octal(va_arg(list, unsigned int), counter);
	else if (c == 'x')
		print_hex(va_arg(list, unsigned int), "0123456789abcdef",
				counter);
	else if (c == 'X')
		print_hex(va_arg(list, unsigned int), "0123456789ABCDEF",
				counter);
}
