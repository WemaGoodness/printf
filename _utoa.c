#include "main.h"

/**
 * _utoa - Converts unsigned integer to string
 * @num: Unsigned integer to be converted
 * @str: Buffer to store the string
 * @base: Base for conversion (e.g., 10, 8, 16)
 *
 * Return: Pointer to the resulting string
 */
char *_utoa(unsigned int num, char *str, int base)
{
	int i = 0;
	int rem, end, start = 0;
	char temp;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	str[i] = '\0';

	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

	return str;
}
