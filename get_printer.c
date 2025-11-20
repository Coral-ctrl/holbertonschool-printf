#include "main.h"
#include <stdio.h>

/**
 * get_printer - matches format to element in symbol array
 * @format: character in format string to check if in symbol array
 * Return: function pointer
 */

int (*get_printer(char format))(va_list, local_buffer_t *buffptr)
{
	int i;

	printer_t symbol[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex_lower},
		{"X", print_hex_upper},
		{"S", print_S_string},
		{NULL, NULL}
	};

	i = 0;
	while (symbol[i].arg != NULL && format != symbol[i].arg[0])
		i++;
	return (symbol[i].f);
}
