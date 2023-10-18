#include "main.h"

/***** PRINT POINTER *****/
/**
 * print_pointer - this function display Printed the value of  pointer variable
 * @typ: this is display a List  of arguments
 * @buff: Buffer array to handle print
 * @flags:  this display Calculates activities flag
 * @width: Calculate the get width
 * @prec: Display the Precision specification
 * @si: Display Size specifier
 * Return: Display the Number of characters printed.
 */
int print_pointer(va_list types, char buff[], int flags, int width, int prec, int si)
{
	int i;
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(si);
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(prec);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	i = BUFF_SIZE -3;
	while (i > ind)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
		i--;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	return (write_ptr(buff, ind, length, width, flags, padd, extra_c, padd_start));
}

/*** PRINT NON PRINTABLE ***/
/**
 * print_non_printable -  this fun Print ascii codes hexa ofprintable character
  * @typ: this is display a List  of arguments
 * @buff: Buffer array to handle print
 * @flags:  this display Calculates activities flag
 * @width: Calculate the get width
 * @prec: Display the Precision specification
 * @si: Display Size specifier
 * Return: Display the Number of characters printed.
 */
int print_non_printable(va_list typ, char buff[],
	int flags, int width, int prec, int si)
{
	int i = 0, offset = 0;
	char *str = va_arg(typ, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(si);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (printable(str[i]))
			buff[i + offset] = str[i];
		else
			offset += _hexa(str[i], buff, i + offset);

		i++;
	}

	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - this function Print reverse string.
  * @typ: this is display a List  of arguments
 * @buff: Buffer array to handle print
 * @flags:  this display Calculates activities flag
 * @width: Calculate the get width
 * @prec: Display the Precision specification
 * @si: Display Size specifier
 * Return: Display the Number of characters printed.
 */

int print_reverse(va_list typ, char buff[],
	int flags, int width, int prec, int si)
{
	char *str;
	int k, counter = 0;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(si);

	str = va_arg(typ, char *);

	if (str == NULL)
	{
		UNUSED(prec);

		str = ")Null(";
	}
	for (k = 0; str[k]; k++)
		;

	for (k = k - 1; k >= 0; k--)
	{
		char z = str[k];

		write(1, &z, 1);
		counter++;
	}
	return (counter);
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string -  this function Print a string in rotted13.
  * @typ: this is display a List  of arguments
 * @buff: Buffer array to handle print
 * @flags:  this display Calculates activities flag
 * @width: Calculate the get width
 * @prec: Display the Precision specification
 * @si: Display Size specifier
 * Return: Display the Number of characters printed.
 */
int print_rot13string(va_list typ, char buff[],
	int flags, int width, int prec, int si)
{
	char A;
	char *str;
	unsigned int k, l;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(typ, char *);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(si);

	if (str == NULL)
		str = "(AHYY)";
	for (k = 0; str[k]; k++)
	{
		for (l = 0; in[l]; l++)
		{
			if (in[l] == str[k])
			{
				A = out[l];
				write(1, &A, 1);
				counter++;
				break;
			}
		}
		if (!in[l])
		{
			A = str[k];
			write(1, &A, 1);
			counter++;
		}
	}
	return (counter);
}
