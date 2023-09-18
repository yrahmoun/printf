#include "main.h"

/**
 * handle_specifiers - handles the printf specifiers
 * @list: arguments passed to the printf function
 * @format: string containing the specifiers
 * @counter: counts characters printed
 * @index: current index in the format string
 */


void handle_specifiers(va_list list, const char *format,
		int *counter, int index)
{
	if (format[index + 1] == 'c')
		_putchar(va_arg(list, int), counter);
	else if (format[index + 1] == '%')
		_putchar('%', counter);
	else if (format[index + 1] == 's')
		print_string(va_arg(list, char *), counter);
}

/**
 * _printf - prints anything passed to it
 * @format: string holding what to print
 * Return: number of characters printed by the function
 */

int _printf(const char *format, ...)
{
	va_list list;
	int counter = 0;
	int i = 0;

	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			handle_specifiers(list, format, &counter, i);
			i++;
		}
		else
			_putchar(format[i], &counter);
		i++;

	}
	va_end(list);
	return (counter);
}

/**
 *  * print_int - prints an integer
 *   * @num: the integer to be printed
 *    * @counter: counts characters printed
 *     */
void print_int(int num, int *counter)
{
	int temp = num;
	int count = 0;

	// Handle the case where the number is 0
	if (num == 0)
	{
		_putchar('0', counter);
		return;
	}

	while (temp != 0)
	{
		temp /= 10;
		count++;
	}

	// Handle negative numbers
	if (num < 0)
	{
		_putchar('-', counter);
		num = -num;
	}

	while (count > 0)
	{
		int divisor = 1;

		for (int i = 1; i < count; i++)
		{
			divisor *= 10;
		}
		int digit = (num / divisor) % 10;

		_putchar(digit + '0', counter);
		count--;
	}
}
