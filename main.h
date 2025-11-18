#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _putchar(char c);

int _printf(const char *format, ...);

int (*get_printer(char format))(va_list);

int print_char(va_list args);

int print_string(va_list args);

int print_percent(va_list args);

int print_int(va_list args);

int print_number(unsigned int n);
/**
 * struct printer - Struct printer
 * @arg: format
 * @f: The function associated
 */
typedef struct printer
{
	char *arg;
	int (*f)(va_list);
} printer_t;

#endif
