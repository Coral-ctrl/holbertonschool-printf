#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
* _printf - produces output according to a format
* @format: format string
*
* Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{

		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
				return (count);

			func = get_printer(format[i]);

			if (func != NULL)
				count += func(args);
			else
			{
				return (count);
				/* count += _putchar('%');
				   count += _putchar(format[i]); */
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
