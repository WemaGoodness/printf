#include "main.h"

/**
 * _itoa - Converts integer to string
 * @num: integer to be converted
 * @str: buffer to store string
 * @base: base for conversion
 *
 * Return: Pointer to string
 */
char *_itoa(int num, char *str, int base)
{
	int i = 0, start = 0, end, rem;
	int isNegative = 0;
	char temp;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	if (num < 0 && base != 10)
	{
		isNegative = 1;
		num = -num;
	}

	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	if (isNegative && base != 10)
		str[i++] = '-';

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
