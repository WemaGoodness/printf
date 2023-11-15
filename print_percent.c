#include "main.h"

/**
 * print_percent - prints %
 * @buffer: memory size
 * @len: string length
 * 
 * Return: 1
 */
int print_percent(va_list args, char *buffer, int len)
{
	(void)args;
	_putchar(buffer, '%', len);
	return (1);
}
