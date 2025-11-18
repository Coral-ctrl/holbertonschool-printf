#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_string - print string
 * @args: variadic list containing the argument to print
 * Return: i to show length
 */

int print_string(va_list args)
{
	int i;
	char *string;

	string = va_arg(args, char *);

	if (string == NULL)
		string = "(null)";

	i = 0;
	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
	return (i);
}
