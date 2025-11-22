#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_octal - prints an unsigned integer in octal
 * @args: variadic list containing the unsigned integer
 * @buffptr: pointer to buffer
 * @flag: pointer to flag struct
 * Return: number of characters printed
 */

int print_octal(va_list args, local_buffer_t *buffptr, flag_t *flag)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	if (flag->hash && num !=0)
		count += _putchar('0', buffptr);
	count += print_octal_recursive(num, buffptr);

	return (count);
}
/**
 * print_octal_recursive - helper function to print octal recursively
 * @n: unsigned integer to print in octal
 * @buffptr: pointer to buffer
 * Return: number of characters printed
 */
int print_octal_recursive(unsigned int n, local_buffer_t *buffptr)
{
	int count = 0;

	if (n / 8)
		count += print_octal_recursive(n / 8, buffptr);

	_putchar((n % 8) + '0', buffptr);
	count++;

	return (count);
}
