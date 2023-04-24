#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/* print string */
/**
  * print_string - Prints a string
  * @args: List a of arguments
  * @bfr: Buffer array to handle print
  * @flg:  Calculates active flags
  * widt: get width
  * @prec: Precision specification
  * @size: Size specifier
  * Return: Number of characters printed
  */
int print_string(va_list args, char bfr[],
	int flg, int widt, int prec, int size)
{
	int lenn;
	char *sttr = va_arg(args, char *);


	UNUSED(bfr);
	UNUSED(flg);
	UNUSED(widt);
	UNUSED(prec);
	UNUSED(size);

	if (sttr == NULL)
		sttr = "(null)";
	if (prec >= 6)
		sttr = "      ";



	return (print_stg);
}
