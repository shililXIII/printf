#include "main.h"

/**
 * ha_print - prints args based on its type
 * @fmt: Formatted str in which to print the args.
 * @list: List of args to print.
 * @ind: ind..
 * @buff: Buff arr handle print.
 * @flags: Calc active flags
 * @width: get width.
 * @prec: precision specification
 * @si: Size specifier
 * Return: 1 or 2;
 */

int ha_print(const char *fmt, int *ind, va_list list, char buff[],
		int flags, int width, int prec, int si)
{
	int i, unknow_len = 0, pc = -1;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'i', print_int},
		{'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal},
		{'x', print_hexadecimal}, {'X', print_hexa_upper},
		{'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string},
		{'\0', NULL}
	};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
		return (fmt_types[i].fn(list, buff, flags, width, prec, si));
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (pc);
}
