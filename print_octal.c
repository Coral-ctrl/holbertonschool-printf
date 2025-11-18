#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_octal - prints an unsigned integer in octal
 * @args: variadic list containing the unsigned integer
 *
 * Return: number of characters printed
 */

int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	count += print_octal_recursive(num);

	return (count);
}
/**
 * print_octal_recursive - helper function to print octal recursively
 * @n: unsigned integer to print in octal
 *
 * Return: number of characters printed
 */
int print_octal_recursive(unsigned int n)
{
	int count = 0;

	if (n / 8)
		count += print_octal_recursive(n / 8);

	_putchar((n % 8) + '0');
	count++;

	return (count);
}
