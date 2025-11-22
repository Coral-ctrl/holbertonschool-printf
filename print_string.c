#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_string - print string
 * @args: variadic list containing the argument to print
 * @buffptr: pointer to buffer
 * @flag: pointer to flag struct
 * Return: i to show length
 */

int print_string(va_list args, local_buffer_t *buffptr, flag_t *flag)
{
	int i;
	char *string;

	(void)flag;
	
	string = va_arg(args, char *);

	if (string == NULL)
		string = "(null)";

	i = 0;
	while (string[i] != '\0')
	{
		_putchar(string[i], buffptr);
		i++;
	}
	return (i);
}
