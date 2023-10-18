#include "main.h"

/**
 * printable - Evalutions if a char is printable
 * @c: Char 2 be evaluated.
 * Return: 1 when c is printable 0 otherwise
*/

int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * _hexa - Append ascci in hexa code 2 buff
 * @buff: Arr of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */

int _hexa(char ascii_code, char buff[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	
	if (ascii_code < 0)
		ascii_code *= -1;
	buff[i++] = '\\';
	buff[i++] = 'x';
	buff[i++] = map_to[ascii_code / 16];
	buff[i] = map_to[ascii_code % 16];
	return (3);
}

/**
 * is_digit - Verif if a char is a digit
 * @c: Char to be evaluated
 * Return: 1 when c is a digit 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * conv_sz_num - Casts a num to the specified size
 * @num: Num to be casted.
 * @size: Num indicating the type to be casted.
 * Return: Casted value of num
*/

long int conv_sz_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * conv_sz_unsgnd - Casts a num to the specified size
 * @num: Num to be casted
 * @size: Num indicating the type to be casted
 * Return: Casted value num
*/

long int conv_sz_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);

}
