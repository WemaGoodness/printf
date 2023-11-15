#include "main.h"

/**
 * _specifier - handles the conversion specifiers
 * @c: the character
 * @args: the argument list
 * @buffer: the buffer
 * @len: the current length of the buffer
 * Return: the number of characters added to the buffer
 */
int _specifier(char c, va_list args, char *buffer, int len)
{
	int i, count = 0, upper;
	spec_t specs[] = {
		{'c', print_char},
		{'d', print_int},
		{'i', print_int},
		{'s', print_string},
		{'%', print_percent},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hex},
		{'p', print_pointer},
		{'b', print_binary},
		{'S', print_S},
		{'r', print_reverse},
		{'R', print_rot13},
		{'\0', NULL}
	};

	for (i = 0; specs[i].spec; i++)
	{
		if (c == specs[i].spec)
		{
			if (c == 'x' || c == 'X')
				upper = va_arg(args, int);
			else
				upper = 0;
			count = specs[i].f(args, buffer, len);
			return (count);
		}
	}
	count = print_invalid(c, buffer, len);
	return (count);
}

