#include "main.h"
#include <stdio.h>

/**
 * get_printer - matches format to element in symbol array
 * @format: character in format string to check if in symbol array
 * Return: function pointer
 */

int (*get_printer(char format))(va_list)
{
	int i;

	printer_t symbol[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{NULL, NULL}
	};

	i = 0;
	while (symbol[i].arg != NULL && format != symbol[i].arg[0])
		i++;
	return (symbol[i].f);
}
