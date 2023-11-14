#include "main.h"

/**
 * init_buffer - allocates memory
 * @buffer_t: memory size
 * @b: character to allocate memory
 *
 * Return: Success
 */
void init_buffer(buffer_t *b)
{
	b->buffer = malloc(BUFFER_SIZE);
	if (b->buffer == NULL)
		exit(1);

	b->index = 0;
	memset(b->buffer, 0, BUFFER_SIZE);
}
/**
 * flush_buffer - frees memory
 * @buffer_t: memory size
 * @b: character to free memory
 *
 * Return: Success
 */
int flush_buffer(buffer_t *b)
{
	int written = write(1, b->buffer, b->index);
	if (written == -1)
		exit(1);

	b->index = 0;
	memset(b->buffer, 0, BUFFER_SIZE);

	return (written);
}
