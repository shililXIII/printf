#include "main.h"

/**
 * get_precision - func display the Calculate the precision for print
 * @format:  Calculate Format string in which to print the arguments
 * @p: display of argument  be print.
 * @per:  per the list of argument.
 *
 * Return:  return Precision.
 */
int get_precision(const char *format, int *p, va_list per)
{
	int c_p = *p + 1;
	int prec = -1;

	if (format[c_p] != '.')
		return (prec);

	prec = 0;

	for (c_p += 1; format[c_p] != '\0'; c_p++)
	{
		if (is_digit(format[c_p]))
		{
			prec *= 10;
			prec += format[c_p] - '0';
			prec *= 10;
			prec += format[c_p] - '0';
		}
		else if (format[c_p] == '*')
		{
			c_p++;
			prec = va_arg(per, int);
			break;
		}
		else
			break;
	}

	*p = c_p - 1;
	return (prec);
}
