#include "main.h"

/**
 * is_printable - the evaluates if a characters is printable.
 * @c: Characters to be evaluated.
 * Return: 1 if c is printableand 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * append_hexa_code - the append ascci in hexadecimal code to buffer.
 * @buffer: the array.
 * @i: the index to start appending.
 * @ascii_code: ascii codes specifier .
 * Return: Always 3.
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - verification if a characters is a digit.
 * @c: the characters to be evaluated.
 * Return: 1 if c is a digit or 0 otherwise.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: the number specifier to be casted to convert.
 * @size: the number indicating the type to be casted to convert.
 * Return: the casted value of numero
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - the casts a number to the specification size.
 * @num: the number to be casted to convert.
 * @size: the number indicating the type to be casted.
 * Return: the casted value of numero.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
