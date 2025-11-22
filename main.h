#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct local_buffer - struct for local buffer
 * @buffer: pointer to buffer
 * @position: position in buffer
 */
typedef struct local_buffer
{
	char *buffer;
	int position;
} local_buffer_t;

/**
 * struct flags - struct for format flags
 * @plus: plus flag
 * @space: space flag
 * @hash: hash flag
 */
typedef struct flag
{
	int plus;
	int space;
	int hash;
} flag_t;

int _putchar(char c, local_buffer_t *buffptr);

int _printf(const char *format, ...);

int (*get_printer(char format))(va_list, local_buffer_t *buffptr, flag_t *flag);

int print_char(va_list args, local_buffer_t *buffptr, flag_t *flag);

int print_string(va_list args, local_buffer_t *buffptr, flag_t *flag);

int print_percent(va_list args, local_buffer_t *buffptr, flag_t *flag);

int print_binary(va_list args, local_buffer_t *buffptr, flag_t *flag);

int print_int(va_list args, local_buffer_t *buffptr, flag_t *flag);

int print_number(unsigned int n, local_buffer_t *buffptr);

int print_unsigned(va_list args, local_buffer_t *buffptr, flag_t *flag);

int print_unsigned_recursive(unsigned int n, local_buffer_t *buffptr);

int print_octal(va_list args, local_buffer_t *buffptr, flag_t *flag);

int print_octal_recursive(unsigned int n, local_buffer_t *buffptr);

int print_hex_lower(va_list args, local_buffer_t *buffptr, flag_t *flag);

int print_hex_lower_recursive(unsigned int n, local_buffer_t *buffptr);

int print_hex_upper(va_list args, local_buffer_t *buffptr, flag_t *flag);

int print_hex_upper_recursive(unsigned int n, local_buffer_t *buffptr);

int print_S_string(va_list args, local_buffer_t *buffptr, flag_t *flag);

int print_address(va_list args, local_buffer_t *buffptr, flag_t *flag);

/**
 * struct printer - Struct printer
 * @arg: format
 * @f: The function associated
 */
typedef struct printer
{
	char *arg;
	int (*f)(va_list, local_buffer_t *buffptr, flag_t *flag);
} printer_t;

#endif
