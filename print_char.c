#include "main.h"
#include <stdio.h>

/**
 * print_char - prints a char
 * @args: variadic list containing the argument to print
 * Return: int 1 to show length
 */

int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
