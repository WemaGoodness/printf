#include "main.h"

/**
 * _binary - converts to
 * binary equivalent
 * @num: number to convert
 * @buffer_t: memory size
 * @buffer: pointer
 *
 * Return: Success
 */
int _binary(unsigned int num, buffer_t *buffer)
{
	int count = 0, i;
	int num_bits = 0;
	unsigned int temp = num;
	char *binary_str;

	while (temp > 0)
	{
		temp >>= 1;
		num_bits++;
	}

	binary_str = malloc(num_bits + 1);
	if (binary_str == NULL)
		exit(1);

	for (i = num_bits - 1; i >= 0; i--)
	{
		binary_str[i] = (num & 1) + '0';
		num >>= 1;
	}
	binary_str[num_bits] = '\0';

	count += write(1, binary_str, num_bits);
	buffer->index += num_bits;

	free(binary_str);
	return count;
}
<<<<<<< HEAD

=======
>>>>>>> 644fe1499963dd942c43101c944f14fd760de41e
