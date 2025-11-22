#include "main.h"
#include <stdarg.h>
/**
 * print_percent - prints a percent sign
 * @args: unused variadic list
 * @buffptr: pointer to buffer
 * @flag: pointer to flag struct
 * Return: 1
 */
int print_percent(va_list args, local_buffer_t *buffptr, flag_t *flag)
{
	(void)flag;
	(void)args;
	return (_putchar('%', buffptr));
}
