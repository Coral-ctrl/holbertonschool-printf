#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

int (*get_printer(char format))(va_list);

int print_char(va_list);

int print_string(va_list);

typedef struct printer
{
	char *arg;
	int (*f)(va_list);
} printer_t;

#endif
