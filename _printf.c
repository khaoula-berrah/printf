#include "main.h"
#include <stdarg.h>

/**
 * print_string - print sting using flag
 * @str: the string
 * @format: character
 * @flag: the flagindex
 * Return: len
 */
int print_string(char *str, int flag, char form)
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

/**
 * _printf - produces output according to a format.
 * @format: the string uesed to print
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, flag = 0, len = 0;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		switch (format[i])
		{
			case '%':
				if (flag == 1 && format[i + 1] != 'c' && format[i + 1] != 's')
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
				flag = 0;
				break;
			case 's':
				len+= print_string(va_arg(args, char*), flag, format[i]);
				flag = 0;
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