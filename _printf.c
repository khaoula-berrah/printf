<<<<<<< HEAD
#include "main.h"
#include <stdarg.h>
/**
 * _printf - produces output according to a format.
 * @format: the string uesed to print
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, flag = 0, len = 0;
	va_list args;
	char *str;

	va_start(args, format);
	while (format[i])
	{
		switch (format[i])
		{
			case '%':
				if (flag == 1 && format[i + 1] != 's' && format[i + 1] != 'c')
				{
					_putchar('%'), flag = 0, len++; 
					break;
				}
				flag = 1;
				break;
			case 'c':if (flag == 1)
					_putchar(va_arg(args, int));
				else
					_putchar(format[i]);
				len++, flag = 0;
				break;
			case 's':
				if (flag == 1)
				{
					str = va_arg(args, char*);
					while (*str != '\0')
						_putchar(*str), len++, str++;
				}
				else
					_putchar(format[i]), len++;
				flag = 0;
				break;
			default:flag = 0, len++, _putchar(format[i++]);
				continue;
		}
		i++;
	}
	va_end(args);
	return (len);
=======
#include <stdarg.h>
#include <stdio.h>
#include "main.h"
void print_bfr(char bfr[], int *bfr_ind);
/**
  * _printf - Prints formatted output to stdout
  * @format: Format string containing zero or more directives
  * Return: Number of characters printed
  */
int _printf(const char *format, ...)
{
	int i, prnted = 0, print_chars = 0;
	int flg, widt, prec, size, bfr_ind = 0;
	va_list args;
	char bfr[BUFSIZ]

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bfr[bfr_ind++] = format[i];
			if (bfr_ind == BUFSIZ)
				print_bfr(bfr, &bfr_ind);
			print_chars++;
		}
		else
		{
			print_bfr(bfr, &bfr_ind);
			flg = get_flags(format, &i);
			widt = get_width(format, &i, args);
			prec = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			prnted = handle_print(format, &i, args, bfr, flg, widt, prec, size);
			if (prnted == -1)
				return (-1);
			print_chars += prnted;
		}
	}
	print_bfr(bfr, &bfr_ind);
}
/**
  * print_bfr - Prints the contents of the buffer
  * @bfr: Array
  * @bfr_ind: represents the length.
  */
void print_bfr(char bfr[], int *bfr_ind)
{
	if (*bfr_ind > 0)
		write(1, &bfr[0], *bfr_ind);
	*bfr_ind = 0;
>>>>>>> origin/khaoula_printf_branch
}
