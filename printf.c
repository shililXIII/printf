#include "main.h"

void print_buff(char buff[], int *buff_ind);

/**
 * _printf - output the function
 * @format: format.
 * Return: using for Printed characters.
 */
int _printf(const char *format, ...)
{
	int i, p = 0, pc = 0;
	int flags, width, prec, si, buff_ind = 0;
	va_list list;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buff(buff, &buff_ind);
			/* write(1, &format[i], 1);*/
			pc++;
		}
		else
		{
			print_buff(buff, &buff_ind);
			flags = g_flags(format, &i);
			width = g_width(format, &i, list);
			prec = get_precision(format, &i, list);
			si = get_size(format, &i);
			++i;
			p = ha_print(format, &i, list, buff, flags, width, prec, si);
			if (p == -1)
				return (-1);
			pc += p;
		}
	}

	print_buff(buff, &buff_ind);

	va_end(list);

	return (pc);
}

/**
 * print_boff - Print out  the minu of the buffer if it  is the exist
 * @buffer: Enter Array of characters
 * @bu: Index numberv at which to add skip characters, represents the length.
 */
void print_buff(char buff[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buff[0], *buff_ind);
	*buff_ind = 0;
}
