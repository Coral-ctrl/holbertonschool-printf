#include "main.h"
#include <stdarg.h>
/**
 * print_percent - prints a percent sign
 * @args: unused variadic list
 * @buffptr: pointer to buffer
 * Return: 1
 */
int print_percent(va_list args, local_buffer_t *buffptr)
{
	(void)args;
	return (_putchar('%', buffptr));
}
