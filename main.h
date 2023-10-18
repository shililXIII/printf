#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: The format.
 * @fm_t: The function associated.
 */

typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int ha_print(const char *fmt, int *i, va_list list, char buff[], int g_flags, int g_width, int prec, int si);

/**print chars and strings**/
int print_char(va_list typ, char buff[], int flags, int width, int prec, int si);
int print_string(va_list typ, char buff[], int flags, int width, int prec, int si);
int print_percent(va_list typ, char buff[], int flags, int width, int prec, int si);

/**print numbers**/
int print_int(va_list typ, char buff[], int flags, int width, int prec, int si);
int print_binary(va_list typ, char buff[], int flags, int width, int prec, int si);
int print_unsigned(va_list typ, char buff[], int flags, int width, int prec, int si);
int print_octal(va_list typ, char buff[], int flags, int width, int prec, int si);
int print_hexadecimal(va_list typ, char buff[], int flags, int width, int prec, int si);
int print_hexa_upper(va_list typ, char buff[], int flags, int width, int prec, int si);
int print_hexa(va_list types, char map_to[], char buff[], int flags, char flag_ch, int width, int prec, int si);

/**non p**/

int print_non_printable(va_list typ, char buff[], int flags, int width, int prec, int si);

/**print memo addr**/
int print_pointer(va_list typ, char buff[], int flags, int width, int prec, int si);

/**gets**/
int g_flags(const char *format, int *i);
int g_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/**reverse**/
int print_reverse(va_list typ, char buff[], int flags, int width, int prec, int si);

/**rot13**/
int print_rot13string(va_list typ, char buff[], int flags, int width, int prec, int si);

/**width handler**/
int ha_write_char(char c, char buff[], int flags, int width, int prec, int si);
int write_number(int is_positive, int ind, char buffer[], int flags, int width, int prec, int si);
int write_num(int ind, char bff[], int flags, int width, int prec, int length, char padd, char extra_c);
int write_ptr(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int prec, int si);

/**utils**/
int printable(char);
int _hexa(char, char[], int);
int is_digit(char);
long int conv_sz_num(long int num, int size);
long int conv_sz_unsgnd(unsigned long int num, int size);

#endif
