#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
* _printf - produces output according to a format
* @format: format to check
*
* Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0, j;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format != NULL && format[i])
	{

		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);

				j = 0;

				if (s == NULL)
					s = "(null)";
				while (s[j] != '\0')
				{
					write(1, &s[j], 1);
					j++;
					count++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
