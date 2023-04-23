#ifndef MAIN_H
#define MAIN_H
#define BFR_SIZE 1024
#define UNUSED(x) (void)(x)

/* Flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* Size */
#define S_LONG 2
#define S_SHORT 1

/**
  * struct fmmt - Struct op
  * @fmmt: The format.
  * @fnn: The function associated.
  */

struct fmmt
{
	char fmmt;
	int (*fnn)(va_list, char[], int, int, int, int);
};

/**
  * typedef struct fmmt fmmt_t - Struct op
  * @fmmt: The format.
  * @fmmt_t: The function associated.
  */

typedef struct fmmt fmmt_t;
int handle_print(const char *fmmt, int *i,
va_list args, char bfr[], int flg, int widt, int prec, int size);

/* Functions */
int print_string(va_list types, char bfr[], int flg, int widt, int prec, int size);
int print_char(va_list types, char bfr[], int flg, int widt, int prec, int size);
int print_percent(va_list types, char bfr[], int flg, int widt, int prec, int size);

/* Print numbers */
int print_int(va_list types, char bfr[], int flg, int widt, int prec, int size);
int print_binary(va_list types, char bfr[], int flg, int widt, int prec, int size);
int print_unsigned(va_list types, char bfr[], int flg, int widt, int prec, int size);
int print_hexadecimal(va_list types, char bfr[], int flg, int widt, int prec, int size);
int print_hexa_upper(va_list types, char bfr[], int flg, int widt, int prec, int size);



int _putchar(char c);
int _printf(const char *format, ...);
int print_string(const char *format, ...)
#endif

