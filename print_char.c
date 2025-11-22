#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_char - prints a char
 * @args: variadic list containing the argument to print
 * @buffptr: pointer to buffer
 * @flag: pointer to flag struct
 * Return: int 1 to show length
 */

int print_char(va_list args, local_buffer_t *buffptr, flag_t *flag)
{
	(void)flag;
	_putchar(va_arg(args, int), buffptr);
	return (1);
}
