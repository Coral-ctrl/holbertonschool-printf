#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void setup_buffer(local_buffer_t *buffptr);
void empty_buffer(local_buffer_t *buffptr);
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
	int (*func)(va_list, local_buffer_t *buffptr);
	local_buffer_t *buffptr;

	buffptr = (local_buffer_t *) malloc(sizeof(local_buffer_t));

	if (buffptr == NULL || format == NULL)
		return (-1);

	setup_buffer(buffptr);

	va_start(args, format);

	while (buffptr->buffer != NULL && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			func = get_printer(format[i]);

			if (func != NULL)
				count += func(args, buffptr);
			else
			{
				count += _putchar('%', buffptr);
				count += _putchar(format[i], buffptr);
			}
		}
		else
			count += _putchar(format[i], buffptr);
		i++;
	}
	empty_buffer(buffptr);
	va_end(args);
	return (count);
}

/**
 * setup_buffer - mallocs memory for buffer
 * @buffptr: pointer to buffer
 * Return: nothing/ void
 */
void setup_buffer(local_buffer_t *buffptr)
{
	buffptr->buffer = malloc(1024 * sizeof(char));
	buffptr->position = 0;
}

/**
 * empty_buffer - empty the buffer and print what the buffer was holding
 * @buffptr: pointer to buffer
 * Return: nothing/ void
 */
void empty_buffer(local_buffer_t *buffptr)
{
	buffptr->buffer[buffptr->position] = '\0';
	write(1, buffptr->buffer, buffptr->position + 1);
	free(buffptr->buffer);
	free(buffptr);
	buffptr = NULL;
}
