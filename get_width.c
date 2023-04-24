#include "main.h"
/**
  * get_width - the format a variable number of arguments
  * @format: the formatted string in which to print the arguments.
  * @i: modified the value of i in some way
  * @list: the format a variable number of arguments
  * Return: width value
  */
int get_width(const char *format, int *i, va_list list)
{
	int cur_i;
	int widt = 0;

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			widt *= 10;
			widt += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			widt = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (widt);
}
