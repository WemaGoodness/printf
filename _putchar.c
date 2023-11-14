#include "main.h"

/**
 * _putvhar - writes c
 * @c: character to write
 *
 * Return: 1 or -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
