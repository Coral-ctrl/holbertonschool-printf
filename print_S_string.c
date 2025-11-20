#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_S_string - prints a string, converting non-printable chars (ASCII
 *                  < 32 or >=127) to \xXX format where XX is the hex value
 * @args: variadic list containing the argument to print
 * @buffptr: pointer to buffer
 * Return: number of characters printed
 */

int print_S_string(va_list args, local_buffer_t *buffptr)
{
	int i, count = 0;
	char *string;
	unsigned char c;

	string = va_arg(args, char *);

	if (string == NULL)
		string = "(null)";

	for (i = 0; string[i] != '\0'; i++)
	{
		c = string[i];

		if (c < 32 || c >= 127)
		{
			count += _putchar('\\', buffptr);
			count += _putchar('x', buffptr);

			if (c < 16)
				count += _putchar('0', buffptr);

			count += print_hex_upper_recursive(c, buffptr);
		}
		else
			count += _putchar(c, buffptr);
	}

	return (count);
}
