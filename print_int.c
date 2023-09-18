#include "main.h"
/**
 * print_int - prints an integer
 * @num: the integer to be printed
 * @counter: counts characters printed
 */

void print_int(int num, int *counter)
{
	int temp = num;
	int count = 0;

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

	if (num < 0)
	{
		_putchar('-', counter);
		num = -num;
	}

	while (count > 0)
	{
		int divisor = 1;
		int i;
		int digit;

		for (i = 1; i < count; i++)
		{
			divisor *= 10;
		}
		digit = (num / divisor) % 10;
		_putchar(digit + '0', counter);
		count--;
	}
}
