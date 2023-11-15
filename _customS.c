#include "main.h"

/**
 * print_S - handles %S
 * @str: string to print
 * @buffer: buffer to store result
 *
 * Return: Number of characters printed
 */
int print_S(char *str, buffer_t *buffer, int is_uppercase)
{
	int count = 0;

	for (; *str; str++)
	{
		if (*str < 32 || *str >= 127)
		{
			if (buffer->index + 4 >= BUFFER_SIZE)
				count += flush_buffer(buffer);

			count += write(1, "\\x", 2);
			count += write_hex(*str, buffer, is_uppercase);
		}
		else
		{
			if (buffer->index == BUFFER_SIZE)
				count += flush_buffer(buffer);

			buffer->buffer[buffer->index++] = *str;
		}
	}

	return count;
}

/**
 * write_hex - write the hexadecimal
 * representation
 * @c: character to print
 * @buffer: buffer to store result
 * @is_uppercase: caps letter
 *
 * Return: Number of characters printed
 */
int write_hex(char c, buffer_t *buffer, int is_uppercase)
{
	int count = 0;
	char hex_digits[] = "0123456789ABCDEF";

	buffer->buffer[buffer->index++] = hex_digits[(c >> 4) & 0xF];
	if (buffer->index == BUFFER_SIZE)
		count += flush_buffer(buffer);

	buffer->buffer[buffer->index++] = is_uppercase ? hex_digits[c & 0xF] : hex_digits[c & 0xF] + 32;
	if (buffer->index == BUFFER_SIZE)
		count += flush_buffer(buffer);

	return count;
}
