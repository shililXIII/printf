#include "main.h"

/**** PRINT UNSIGNED NUMBER ****/
/**
 * print_unsigned -  this is function used for  Print out   unsigned number
 * @typ:  Display the List  of arguments
 * @buff: used for Calculate Buffer array  handle print
 * @flags:   screen a Calculates activities flag
 * @width: this is calculated get  width
 * @prec:  this is the display Precision specification
 * @si: Calculate the specifier of size
 * Return: Number of characters printed
 */
int print_unsigned(va_list typ, char buff[],
	int flags, int width, int prec, int si)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(typ, unsigned long int);

	n = conv_sz_unsgnd(n, si);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buff[i--] = (n % 10) + '0';
		n /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buff, flags, width, prec, si));
}

/*** PRINT UNSIGNED NUMBER IN OCTAL ***/
/**
 * print_octal - this is fun for Prints an unsigned number in octal notation
 * @typ:  Display the List  of arguments
 * @buff: used for Calculate Buffer array  handle print
 * @flags:   screen a Calculates activities flag
 * @width: this is calculated get  width
 * @prec:  this is the display Precision specification
 * @si: Calculate the specifier of size
 * Return: Number of characters printed.
 */
int print_octal(va_list typ, char buff[],
	int flags, int width, int prec, int si)
{

	int i = BUFF_SIZE - 2;
	unsigned long int nu = va_arg(typ, unsigned long int);
	unsigned long int init_nu = nu;

	UNUSED(width);

	nu = conv_sz_unsgnd(nu, si);

	if (nu == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (nu > 0)
	{
		buff[i--] = (nu % 8) + '0';
		nu /= 8;
	}

	if (flags & F_HASH && init_nu != 0)
		buff[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buff, flags, width, prec, si));
}

/***** PRINT UNSIGNED NUMBER IN HEXADECIMAL ****/
/**
 * print_hexadecimal - cat Print  unsigned number  hexadecimal notation
 * @typ:  Display the List  of arguments
 * @buff: used for Calculate Buffer array  handle print
 * @flags:   screen a Calculates activities flag
 * @width: this is calculated get  width
 * @prec:  this is the display Precision specification
 * @si: Calculate the specifier of size
 * Return: Number of characters printed.
 */
int print_hexadecimal(va_list typ, char buff[],
	int flags, int width, int prec, int si)
{
	return (print_hexa(typ, "0123456789abcdef", buff,
		flags, 'x', width, prec, si));
}

/*** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ***/
/**
 * print_hexa_upper - dsp fun for unsigned number in upper hexadecimal notation
 * @typ:  Display the List  of arguments
 * @buff: used for Calculate Buffer array  handle print
 * @flags:   screen a Calculates activities flag
 * @width: this is calculated get  width
 * @prec:  this is the display Precision specification
 * @si: Calculate the specifier of size
 * Return: Number of characters printed.
 */
int print_hexa_upper(va_list typ, char buff[],
	int flags, int width, int prec, int si)
{
	return (print_hexa(typ, "0123456789ABCDEF", buff,
		flags, 'X', width, prec, si));
}

/*** PRINT HEXX NUM IN LOWER OR UPPER ****/
/**
 * print_hexa - this  fun using aPrint a hexadecimal number lower or upper case
 * @typ: Display the List  of arguments
 * @map_to: Array of value  map the number to
 * @buff: Calculate a Buffer array to handle print
 * @flags:  screen a Calculates activitiesflag
 * @flag_ch: screen a Calculates activities flag
 * @width: is calculated get  width
 * @prec: this is the display Precision specification
 * @si: Calculate the specifier of size
 * @si: Calculate the specifier of size
 * Return:  return a Number of characters printed
 */
int print_hexa(va_list typ, char map_to[], char buff[],
	int flags, char flag_ch, int width, int prec, int si)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(typ, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = conv_sz_unsgnd(number, si);

	if (number == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[i--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && init_number != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;
	return (write_unsgnd(0, i, buff, flags, width, prec, si));
}
