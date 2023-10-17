#include "main.h"

/***** PRINT CHAR *****/

/**
* print_char - Print out   character
* @typ: Display List an argument
* @buff: Display Buffer array to handle print
* @flags:  can be Calculates activities in flags
* @width:  Display Width
* @prec: Display Precision specification
* @si: Calculate a Size of specifier
* Return: Number of characters printed
*/
int print_char(va_list typ, char buff[],
int flags, int width, int prec, int si)
{
char c = va_arg(typ, int);

return (ha_write_char(c, buff, flags, width, prec, si));
}
/***** PRINT A STRING *****/
/**
* print_string - can Display avPrint of a string
* @typ:  Display a List  of arguments
* @buff: can be Calculates Buffer array to handle print
* @flags:  can be Calculates active flags
* @width: take a  get of width.
* @prec: Precision specification
* @si: Size specifier
* Return: Display aNumber of characters printed
*/
int print_string(va_list typ, char buff[],
int flags, int width, int prec, int si)
{
	int length = 0, i;
	char *str = va_arg(typ, char *);

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(si);
	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (prec >= 0 && prec < length)
		length = prec;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/***** PRINT PERCENT SIGN *****/
/**
* print_percent -  Display a Print of apercent signs
* @typ:  Display a List of arguments
* @buff: can be created Buffer array to handle prints
* @flags: can be  Calculate active flag
* @width: get width.
* @prec:  Display a Precision specification
* @si: Size specifier
* Return: screen a Number of character printed
*/
int print_percent(va_list typ, char buff[],
int flags, int width, int prec, int si)
{
	UNUSED(typ);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(si);
	return (write(1, "%%", 1));
}

/***** PRINT INT *****/
/**
* print_int -  Display the Print integers
* @typ: screen a List of arguments
* @buff: can be Calculates Buffer array to handle prints
* @flags: must be Calculate activities flags
* @width: get width.
* @prec: abbreviation for Precision specifice
* @si: Size specifier
* Return:  must be return Number of characters printed
*/
int print_int(va_list typ, char buff[],
int flags, int width, int prec, int si)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = conv_sz_num(n, si);
	if (n == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buff, flags, width, prec, si));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - this is function display Print an unsigned number
 * @typ: display the type of List of arguments
 * @buff: screen Buffer array to handle print
 * @flags:  work up Calculates activated in flag
 * @width:  special for get width.
 * @prec: display a Precision  specification
 * @si: Size of a  specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list typ, char buff[],
	int flags, int width, int prec, int si)
{
	unsigned int a, b, c, s;
	unsigned int a_array[32];
	int count;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(si);

	a = va_arg(typ, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	a_array[0] = a / b;
	for (c = 1; c < 32; c++)
	{
		b /= 2;
		a_array[c] = (a / b) % 2;
	}
	for (c = 0, s = 0, count = 0; c < 32; c++)
	{
		s += a_array[c];
		if (s || c == 31)
		{
			char z = '0' + a_array[c];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
