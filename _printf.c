#include "main.h"

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
			else
			{
				_putchar('%', &counter);
				if (format[i])
					_putchar(format[i], &counter);
			}
		}
		else
			_putchar(format[i], &counter);
		i++;
	}
	va_end(list);
	return (counter);
}
