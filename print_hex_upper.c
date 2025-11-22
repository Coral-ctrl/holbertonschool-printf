#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_hex_upper - prints an unsigned integer in uppercase hexadecimal
 * @args: variadic list containing the unsigned integer
 * @buffptr: pointer to buffer
 * @flag: pointer to flag struct
 * Return: number of characters printed
 */

int print_hex_upper(va_list args, local_buffer_t *buffptr, flag_t *flag)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	if (flag->hash && num != 0)
	{
		count += _putchar('0', buffptr);
		count += _putchar('X', buffptr);
	}
	count += print_hex_upper_recursive(num, buffptr);

	return (count);
}
/**
 * print_hex_upper_recursive - helper function to print hex recursively
 * @n: unsigned integer to print in hexadecimal
 * @buffptr: pointer to buffer
 * Return: number of characters printed
 */
int print_hex_upper_recursive(unsigned int n, local_buffer_t *buffptr)
{
	int count = 0;

	if (n / 16)
		count += print_hex_upper_recursive(n / 16, buffptr);

	if ((n % 16) < 10)
		_putchar((n % 16) + '0', buffptr);
	else
		_putchar((n % 16) - 10 + 'A', buffptr);
	count++;

	return (count);
}
