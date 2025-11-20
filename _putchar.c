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

	if (buffptr->position < 1024)
	{
		buffptr->buffer[buffptr->position] = c;
		buffptr->position++;
	}
	else
	{
		write(1, buffptr->buffer, buffptr->position);
		buffptr->position = 0;
	}
	return (1);
}
