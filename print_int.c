#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_int - prints integer
 * @args: variadic list containing the integer
 *
 * Return: number of characters printed
 */

int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
		num = n;

	count += print_number(num);

	return (count);
}
/**
 * print_number - helper function to print numbers recursively
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_number(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_number(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}
