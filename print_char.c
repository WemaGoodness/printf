#include "main.h"

/**
 * print_char - prints a character
 * @args: the argument list
 * @buffer: the buffer
 * @len: the current length of the buffer
 * Return: 1
 */
int print_char(va_list args, char *buffer, int len)
{
	char c;

	c = va_arg(args, int);
	_putchar(buffer, c, len);
	return (1);
}
