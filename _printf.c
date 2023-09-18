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
	else if (format[index + 1] == 'd' || format[index + 1] == 'i')
		print_int(va_arg(list, int), counter);
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

	if (!format || (format[0] == '%' && !format[1]))
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
