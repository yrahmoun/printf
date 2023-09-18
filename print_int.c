#include <stdlib.h>
#include "main.h"
/**
 * print_int - prints an integer
 * @num: the integer to be printed
 * @counter: counts characters printed
 */

void print_int(int num, int *counter)
{
	int is_nigative =0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0', counter);
		return;
	}

	int num_digits;
	int temp;

	num_digits = 0;
	temp = num;

	while (temp > 0)
	{
		temp /= 10;
		num_digits++;
	}

	char *digits = (char *)malloc((num_digits + 1 + is_negative) * sizeof(char));
	if (!digits)
	{
		// here we should handle memory allocation failure but no need to rn
		return;

	}
	int index;

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

	// print string in reverse since it was reversed before
	int i;

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(digits[i], counter);
	}
	free(digits);
}
