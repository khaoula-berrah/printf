#include <stdarg.h>
#include <stdio.h>
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
	char bfr[BUFF_SIZE];

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bfr[bfr_ind++] = format[i];
			if (bfr_ind == BUFF_SIZE)
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
}
