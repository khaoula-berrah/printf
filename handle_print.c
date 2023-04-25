#include "main.h"
/**
  * handle_input - print an argument based on it type
  * @fmt: the formatted string in which to print the arguments.
  * @list: va_list of arguments to be printed.
  * @ind: the buffer array to be used for printing.
  * @buffer: the buffer array to handle print.
  * @flags: the calculates active flags
  * @width: get width argument
  * @precision: the precision specification for printing
  * @size: Size specifier for printing.
  * Return: the number 1 or 2
  */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_lenn = 0, prnted_chaars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_lenn += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_lenn += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_lenn += write(1, &fmt[*ind], 1);
		return (unknow_lenn);
	}
	return (prnted_chaars);
}
