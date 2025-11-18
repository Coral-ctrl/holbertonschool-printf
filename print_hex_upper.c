#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_hex_upper - prints an unsigned integer in uppercase hexadecimal
 * @args: variadic list containing the unsigned integer
 *
 * Return: number of characters printed
 */

int print_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	count += print_hex_upper_recursive(num);

	return (count);
}
/**
 * print_hex_upper_recursive - helper function to print hex recursively
 * @n: unsigned integer to print in hexadecimal
 *
 * Return: number of characters printed
 */
int print_hex_upper_recursive(unsigned int n)
{
	int count = 0;

	if (n / 16)
		count += print_hex_upper_recursive(n / 16);

	if ((n % 16) < 10)
		_putchar((n % 16) + '0');
	else
		_putchar((n % 16) - 10 + 'A');
	count++;

	return (count);
}
