#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <alloca.h>

void print_buffer(char buffer[], int *buff_ind);
/**
  * print_buffer - print character to a buffer.
  * @buffer: buffer to print the character to
  * @buff_ind: the represents the length.
  */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
/**
  * _printf - custom printf function
  * @format: string literal containing format specifiers
  * Return: number of characters printed
  */
int _printf(const char *format, ...)
{
	int i, prnted = 0, prnted_chaars = 0;
	int flg, widt, prec, size, buffer_ind = 0;
	va_list lst;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lst, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_ind++] = format[i];
			if (buffer_ind == BUFF_SIZE)
				print_buffer(buffer, &buffer_ind);
			prnted_chaars++;
		}
		else
		{
			print_buffer(buffer, &buffer_ind);
			flg = get_flags(format, &i);
			widt = get_width(format, &i, lst);
			prec = get_precision(format, &i, lst);
			size = get_size(format, &i);
			++i;
			prnted = handle_print(format, &i, lst, buffer,
				flg, widt, prec, size);
			if (prnted == -1)
				return (-1);
			prnted_chaars += prnted;
		}
	}
	print_buffer(buffer, &buffer_ind);
	va_end(lst);
	return (prnted_chaars);
}
