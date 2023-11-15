#ifndef MAIN_h
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * struct buffer - struct for handling the buffer
 * @buffer: pointer to a character buffer
 * @index: index to keep track of the current position in the buffer
 */
typedef struct buffer
{
	char *buffer;
	int index;
} buffer_t;

int _putchar(char c);
void init_buffer(buffer_t *b);
int flush_buffer(buffer_t *b);
int _printf(const char *format, ...);
char *_itoa(int num, char *str, int base);
char *_utoa(unsigned int num, char *str, int base);
int _binary(unsigned int, buffer_t *);
int print_address(va_list l, buffer_t *buffer);
int print_S(char *str, buffer_t *buffer, int is_uppercase);
int write_hex(char c, buffer_t *buffer, int is_uppercase);

#endif
