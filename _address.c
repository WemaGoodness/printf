#include "main.h"

/**
 * _address - handles %p
 * @ptr: pointer to print
 * @buffer: buffer to store result
 *
 * Return: Number of characters printed
 */
int _address(void *ptr, buffer_t *buffer)
{
    int count = 0, i;
    char hex_digits[] = "0123456789abcdef";
    char digit;
    int leading_zeros = 1;

    count += write(1, "0x", 2);

    for (i = (sizeof(void *) * 2) - 1; i >= 0; i--)
    {
        digit = hex_digits[((unsigned long)ptr >> (i * 4)) & 0xF];

        if (digit == '0' && leading_zeros)
            continue;

        leading_zeros = 0;

        buffer->buffer[buffer->index++] = digit;
        if (buffer->index == BUFFER_SIZE)
            count += flush_buffer(buffer);
    }

    if (leading_zeros)
        buffer->buffer[buffer->index++] = '0';

    return count;
}
