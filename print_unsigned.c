#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_unsigned - prints an unsigned integer
 * @args: variadic list containing the unsigned integer
 *
 * Return: number of characters printed
 */

int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	count += print_unsigned_recursive(num);

	return (count);
}
/**
 * print_unsigned_recursive - helper function to print unsigned int recursively
 * @n: unsigned integer to print
 *
 * Return: number of characters printed
 */
int print_unsigned_recursive(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned_recursive(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}
