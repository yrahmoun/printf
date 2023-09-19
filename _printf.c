#include "main.h"
#include <ctype.h>
#include <stdlib.h>

/**
 * handle_rest - handles more cases of specifiers
 * @format: string holding specifiers
 * @list: list of arguments
 * @i: current position in the string
 * @counter: counts characters printed
 */

void handle_rest(const char *format, va_list list, int i, int *counter)
{
	if (format[i] == 'u' || format[i] == 'o' || format[i] == 'x'
			|| format[i] == 'X')
		handle_uoxX(format[i], list, counter);
	else if (format[i] == 'r')
	{
		char *input_str = va_arg(list, char *);

		if (input_str)
		{
			char *reversed_str = reverse_string(input_str);

			if (reversed_str)
			{
				print_string(reversed_str, counter);
				free(reversed_str);
			}

		}
	}
	else if (format[i] == 'S')
		handle_S(va_arg(list, char *), counter);
	else
	{
		_putchar('%', counter);
		if (format[i])
			_putchar(format[i], counter);
	}
}

/**
 * _printf - prints anything passed to it
 * @format: string to be printed
 * Return: number of characters printed by the function
 */

int _printf(const char *format, ...)
{
	va_list list;
	int counter = 0;
	int i = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				_putchar(va_arg(list, int), &counter);
			else if (format[i] == '%')
				_putchar('%', &counter);
			else if (format[i] == 's')
				print_string(va_arg(list, char *), &counter);
			else if (format[i] == 'd' || format[i] == 'i')
				print_int(va_arg(list, int), &counter);
			else if (format[i] == 'b')
				print_binary(va_arg(list, unsigned int), &counter);
			else if (format[i] == 'p')
				print_address(va_arg(list, unsigned long), &counter);
			else if (format[i] == 'R')
				print_rot13(va_arg(list, char *), &counter);
			else
				handle_rest(format, list, i, &counter);
		}
		else
			_putchar(format[i], &counter);
		i++;
	}
	va_end(list);
	return (counter);
}
