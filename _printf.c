#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format.
 * @format: the string uesed to print
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, flag = 0, len = 0;
	va_list args;
	char *str;

	va_start(args, format);
	while (format[i])
	{
		switch (format[i])
		{
			case '%':
				if (flag == 1)
				{
					_putchar('%');
					flag = 0;
					len++;
					break;
				}
				flag = 1;
				break;
			case 'c':
				if (flag == 1)
					_putchar(va_arg(args, int));
				else
					_putchar(format[i]);
				len++;
				break;
			case 's':
				str = va_arg(args, char*);
				print_string_flag(str, flag, format[i]);
				len += print_string_flag(str, flag, format[i]);
				break;
			default:
				flag = 0;
				len++;
				_putchar(format[i]);
				i++;
				continue;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/**
 * print_string - to print string
 * @str: the string to print
 * Return: num of character printed
 */
int print_string_flag(char *str, int flag, char form)
{
	int len = 0;

	if (flag == 1)
	{
		while (*str != '\0')
			{
				_putchar(*str);
				len++;
				str++;
			}
	}
	else
	{
		_putchar(form);
		len++;
	}
	return (len);
}