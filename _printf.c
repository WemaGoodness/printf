#include "main.h"

/**
 * _printf - custom printf
 * @format: style
 *
 * Return: Success
 */
int _printf(const char *format, ...)
{
	va_list args;
	buffer_t buffer;
	int count = 0;
	char *str;
	unsigned int x_num, u_num, o_num, X_num;

	init_buffer(&buffer);
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;

			switch (*format)
			{
				case 'c':
					count += flush_buffer(&buffer);
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += flush_buffer(&buffer);
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					count += write(1, str, strlen(str));
					break;
				case '%':
					count += flush_buffer(&buffer);
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					count += write(1, _itoa(va_arg(args, int), buffer.buffer + buffer.index, 10), strlen(buffer.buffer + buffer.index));
					buffer.index += strlen(buffer.buffer + buffer.index);
					break;
				case 'b':
					count += _binary(va_arg(args, unsigned int), &buffer);
					break;
				case 'u':
					count += flush_buffer(&buffer);
					u_num = va_arg(args, unsigned int);
					count += write(1, _utoa(u_num, buffer.buffer + buffer.index, 10), strlen(buffer.buffer + buffer.index));
					buffer.index += strlen(buffer.buffer + buffer.index);
					break;
				case 'o':
					count += flush_buffer(&buffer);
					o_num = va_arg(args, unsigned int);
					count += write(1, _utoa(o_num, buffer.buffer + buffer.index, 8), strlen(buffer.buffer + buffer.index));
					buffer.index += strlen(buffer.buffer + buffer.index);
					break;
				case 'x':
					count += flush_buffer(&buffer);
					x_num = va_arg(args, unsigned int);
					count += write(1, _utoa(x_num, buffer.buffer + buffer.index, 16), strlen(buffer.buffer + buffer.index));
					buffer.index += strlen(buffer.buffer + buffer.index);
					break;
				case 'X':
					count += flush_buffer(&buffer);
					X_num = va_arg(args, unsigned int);
					count += write(1, _utoa(X_num, buffer.buffer + buffer.index, 16), strlen(buffer.buffer + buffer.index));
					buffer.index += strlen(buffer.buffer + buffer.index);
					break;
				default:
					count += flush_buffer(&buffer);
					count += _putchar('%');
					count += _putchar(*format);
			}
		}
		else
		{
			buffer.buffer[buffer.index++] = *format;
			if (buffer.index == BUFFER_SIZE)
				count += flush_buffer(&buffer);
		}
		format++;
	}

	count += flush_buffer(&buffer);
	va_end(args);
	free(buffer.buffer);
	return count;
}
