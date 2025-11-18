#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int *print_binary_rec(unsigned int num, int *length);

/**
 * print_binary - convert unsigned int to binary and print
 * @args: variadic list containing the argument to print
 * Return: i to show length
 */

int print_binary(va_list args)
{
	int length = 0;
	unsigned int num;

	num = va_arg(args, unsigned int);

	if (num == 0)
	{
		_putchar(num + '0');
		length++;
		return (length);
	}

	print_binary_rec(num, &length);

	return (length);
}

/**
 * print_binary_rec - recursively / num by 2 and checks for remainder.
 * Until the number is in its binary state
 * then it prints the binary number 1 digit at a time
 * @num: number to convert to binary
 * @length: pointer to length to track how many numbers have been printed
 * Return: pointer to length
 */

int *print_binary_rec(unsigned int num, int *length)
{
	int remainder;

	remainder = num % 2;

	if (num / 2 != 0)
		print_binary_rec(num / 2, length);

	_putchar(remainder + '0');
	(*length)++;
	return (length);
}
