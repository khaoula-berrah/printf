#include "main.h"
/**
 * handle_write_char - the prints a string  to the buffer.
 * @c: characters types.
 * @buffer: the buffer  specifier for array to handle print.
 * @flags:  the calculates specifier for active flags.
 * @width: field width to be printed.
 * @precision: the precision specifier for printing.
 * @size: the size specifier for printing.
 * Return: the number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int ii = 0;
	char pdd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pdd = '0';

	buffer[ii++] = c;
	buffer[ii] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (ii = 0; ii < width - 1; ii++)
			buffer[BUFF_SIZE - ii - 2] = pdd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - ii - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - ii - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/**
 * write_number - the prints a string  to the buffer.
 * @is_negative: va_list containing the string to be printed.
 * @ind: caracters types.
 * @buffer: the buffer specifier for array to handle print.
 * @flags:  the calculates specifier for active flags
 * @width: field width to be printed.
 * @precision: the precision specifier for printing.
 * @size: the size specifier for printing.
 * Return: the number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int lent = BUFF_SIZE - ind - 1;
	char pdd = ' ', extr_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pdd = '0';
	if (is_negative)
		extr_ch = '-';
	else if (flags & F_PLUS)
		extr_ch = '+';
	else if (flags & F_SPACE)
		extr_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		lent, pdd, extr_ch));
}

/**
 * write_num - the write a number using a bufffer.
 * @ind: Index at which the number starts on the buffer
 * @buffer: the buffer specifier.
 * @flags: the flags specifier.
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 * Return: the number of printed characters.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int ii, pdd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (ii = 1; ii < width - length + 1; ii++)
			buffer[ii] = padd;
		buffer[ii] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], ii - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], ii - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--pdd_start] = extra_c;
			return (write(1, &buffer[pdd_start], ii - pdd_start) +
				write(1, &buffer[ind], length - (1 - pdd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - to Writes an unsigned number specifier.
 * @is_negative: the number indicating if the numero negative.
 * @ind: Index at which the number starts in the buffer.
 * @buffer: the array of characters.
 * @flags: the flags specifiers fot printing.
 * @width: the Width specifier for printing.
 * @precision: the precision specifier.
 * @size: the size specifier.
 * Return: the number of written characters.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int lent = BUFF_SIZE - ind - 1, i = 0;
	char pdd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < lent)
		pdd = ' ';

	while (precision > lent)
	{
		buffer[--ind] = '0';
		lent++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pdd = '0';

	if (width > lent)
	{
		for (i = 0; i < width - lent; i++)
			buffer[i] = pdd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], lent) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], lent));
		}
	}

	return (write(1, &buffer[ind], lent));
}

/**
 * write_pointer - to write a memory addres.
 * @buffer: the arrays of characters.
 * @ind: the index the number starts in the buffer.
 * @length: the length specifier of number.
 * @width: the width specifier for printing.
 * @flags: the flags specifier for printing.
 * @padd: Characters representing the padding.
 * @extra_c: Characters representing extra characters
 * @padd_start: the index for padding should start
 *
 * Return: the number of written characters.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int ii;

	if (width > length)
	{
		for (ii = 3; ii < width - length + 3; ii++)
			buffer[ii] = padd;
		buffer[ii] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], ii - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], ii - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], ii - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
