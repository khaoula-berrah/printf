#include <stdarg.h>
#include <stdio.h>
/**
  * print_string - Prints formatted output to stdout
  * @format: Format string containing zero or more directives
  * Return: Number of characters printed
  */
int print_string(const char *format, ...)
{
	va_list args;
	int print_stg;

	va_start(args, format);
	print_stg = print_string(format, args);
	va_end(args);

	return (print_stg);
}
