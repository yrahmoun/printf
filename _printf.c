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
 * check_errors - checks for errors in _printf
 * @s: format string
 * Return: 1 or 0
 */

int check_errors(char *s)
{
	int i = 0;

	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			while (s[i] <= 32)
				i++;
			if (!s[i])
				return (1);
		}
		i++;
	}
	return (0);
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

	if (check_errors(format))
		return (-1);
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
