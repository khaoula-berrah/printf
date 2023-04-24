#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
  * print_char - print character to a buffer.
  * @types: a va_list of arguments
  * @buffer: buffer to print the character to
  * @flags: flags used to format the output
  * @width: field width to use when formatting the output
  * @precision: precision to use when formatting the output
  * @size: maximum number of bytes to print
  * Return: number of bytes printed to the buffer
  */

/*print_charactere*/

int print_char(char types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char n = ' ';
	/*char buffer[BUFF_SIZe]*/

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		n = '0';

	buffer[i++] = types;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = n;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));


}

/**
  * _printf - custom printf function
  * @format: string literal containing format specifiers
  * Return: number of characters printed
  */


int _printf(const char *format, ...)
{
	va_list args;
	int lengt;
	int num_printed = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					lengt = va_arg(args, int);
					num_printed += printf("%d", lengt);
					break;
					default:
					putchar('%');
					putchar(*format);
					num_printed += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			num_printed++;
		}
		format++;
	}
	va_end(args);
	return (num_printed);
}
