#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format.
 * @format: the string uesed to print
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, flag = 0;
	va_list args;
	char *str;

	va_start(args, format);
	while (format[i])
	{
		switch (format[i])
		{
			case '%':
				flag = 1;
				break;
			case 'c':
				if (flag == 1)
					_putchar(va_arg(args, int));
				else
					_putchar(format[i]);
				break;
			case 's':
				if (flag == 1)
				{
					str = va_arg(args, char*);
					while (*str != '\0')
					{
						_putchar(*str);
						str++;
					}
				}
				else
					_putchar(format[i]);
				break;
			default:
				flag = 0;
				_putchar(format[i]);
				continue;
		}
		i++;
	}
	va_end(args);
	return (i);
}
