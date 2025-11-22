#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_int - prints integer
 * @args: variadic list containing the integer
 * @buffptr: pointer to buffer
 * @flag: pointer to flag struct
 * Return: number of characters printed
 */

int print_int(va_list args, local_buffer_t *buffptr, flag_t *flag)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-', buffptr);
		count++;
		num = -n;
	}
	else
	{
		if (flag->plus)
			count += _putchar('+', buffptr);
		else if (flag->space)
			count += _putchar(' ', buffptr);
		num = n;
	}

	count += print_number(num, buffptr);

	return (count);
}
/**
 * print_number - helper function to print numbers recursively
 * @n: number to print
 * @buffptr: pointer to buffer
 * Return: number of characters printed
 */
int print_number(unsigned int n, local_buffer_t *buffptr)
{
	int count = 0;

	if (n / 10)
		count += print_number(n / 10, buffptr);

	_putchar((n % 10) + '0', buffptr);
	count++;

	return (count);
}
