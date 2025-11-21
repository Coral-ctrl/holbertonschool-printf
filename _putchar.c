#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @buffptr: pointer to buffer
 * Return: On success 1
 */
int _putchar(char c, local_buffer_t *buffptr)
{
	buffptr->buffer[buffptr->position] = c;
	
	if (buffptr->position == 1023)
	{
		write(1, buffptr->buffer, buffptr->position + 1);
		buffptr->position = 0;
		return (1);
	}
	buffptr->position++;
	return (1);
}
