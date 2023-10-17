#include "main.h"

void print_boff(char buffer[], int *bu);

/**
 * _printf - output the function
 * @format: format.
 * Return: using for Printed characters.
 */
int _printf(const char *format, ...)
{
	int i, p = 0, pc = 0;
	int f, w, prec, s, bu = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[bu++] = format[i];
			if (bu == BUFF_SIZE)
				print_boff(buffer, &bu);
			/* write(1, &format[i], 1);*/
			pc++;
		}
		else
		{
			print_boff(buffer, &bu);
			f = g_flags(format, &i);
			w = g_width(format, &i, list);
			prec = get_precision(format, &i, list);
			s = get_size(format, &i);
			++i;
			p = handle_print(format, &i, list, buffer,
				f, w, prec, s);
			if (p == -1)
				return (-1);
			pc += p;
		}
	}

	print_boff(buffer, &bu);

	va_end(list);

	return (pc);
}

/**
 * print_boff - Print out  the minu of the buffer if it  is the exist
 * @buffer: Enter Array of characters
 * @bu: Index numberv at which to add skip characters, represents the length.
 */
void print_boff(char buffer[], int *bu)
{
	if (*bu > 0)
		write(1, &buffer[0], *bu);

	*bu = 0;
}
