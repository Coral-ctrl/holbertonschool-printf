#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void setup_buffer(local_buffer_t *buffptr);
void empty_buffer(local_buffer_t *buffptr);
void init_flags(flag_t *flag);
int parse_flags(const char *format, int *i, flag_t *flag);

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
	int (*func)(va_list, local_buffer_t *buffptr, flag_t *flag);
	local_buffer_t *buffptr;
	flag_t flag;

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
			init_flags(&flag);
			parse_flags(format, &i, &flag);

			func = get_printer(format[i]);

			if (func != NULL)
				count += func(args, buffptr, &flag);
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
 * init_flags - initialize flags struct
 * @flags: pointer to flags struct
 * Return: nothing/void
 */
void init_flags(flag_t *flag)
{
	flag->plus = 0;
	flag->space = 0;
	flag->hash = 0;
}

/**
 * parse_flags - parse flag characters
 * @format: format string
 * @i: pointer to current position in format string
 * @flag: pointer to flag struct
 * Return: number of flags parsed
 */
int parse_flags(const char *format, int *i, flag_t *flag)
{
	int count = 0;

	while (format[*i] == '+' || format[*i] == ' ' ||
	       format[*i] == '#')
	{
		if (format[*i] == '+')
			flag->plus = 1;
		else if (format[*i] == ' ')
			flag->space = 1;
		else if (format[*i] == '#')
			flag->hash = 1;
		(*i)++;
		count++;
	}
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
	write(1, buffptr->buffer, buffptr->position);
	free(buffptr->buffer);
	free(buffptr);
	buffptr = NULL;
}
