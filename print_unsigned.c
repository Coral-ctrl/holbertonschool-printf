#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_unsigned - prints an unsigned integer
 * @args: variadic list containing the unsigned integer
 * @buffptr: pointer to buffer
 * Return: number of characters printed
 */

int print_unsigned(va_list args, local_buffer_t *buffptr)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	count += print_unsigned_recursive(num, buffptr);

	return (count);
}
/**
 * print_unsigned_recursive - helper function to print unsigned int recursively
 * @n: unsigned integer to print
 * @buffptr: pointer to buffer
 * Return: number of characters printed
 */
int print_unsigned_recursive(unsigned int n, local_buffer_t *buffptr)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned_recursive(n / 10, buffptr);

	_putchar((n % 10) + '0', buffptr);
	count++;

	return (count);
}
