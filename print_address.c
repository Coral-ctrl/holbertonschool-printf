#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int *print_addr_rec(unsigned long num, int *length, local_buffer_t *buffptr);

/**
 * print_address - prints memory address
 * @args: variadic list containing the address
 * @buffptr: pointer to buffer
 * @flag: pointer to flag struct (unused)
 * Return: number of characters printed
 */

int print_address(va_list args, local_buffer_t *buffptr, flag_t *flag)
{
	unsigned long num = va_arg(args, unsigned long);
	int length = 0;

	(void)flag;
	
	if (num == '\0')
	{
		length += _printf("%s", "(nil)");
		return (length);
	}

	length += _putchar(0 + '0', buffptr);
	length += _putchar(0 + 'x', buffptr);

	print_addr_rec(num, &length, buffptr);

	return (length);
}
/**
 * print_addr_rec - uses recursion to convert num to hex and print
 * @num: unsigned long to print memory address
 * @length: pointer to length
 * @buffptr: pointer to buffer
 * Return: number of characters printed
 */
int *print_addr_rec(unsigned long num, int *length, local_buffer_t *buffptr)
{
	int remainder;

	remainder = num % 16;

	if (num / 16 != 0)
		print_addr_rec(num / 16, length, buffptr);


	if ((num % 16) < 10)
		_putchar((remainder % 16) + '0', buffptr);

	else
		_putchar((remainder % 16) - 10 + 'a', buffptr);

	(*length)++;

	return (length);
}
