#include "main.h"

/**
 * get_size - this fun for  Calculates the size to next the argument
 * @format: calculates a  Formatted string in which into print the arguments
 * @p: display the  List of arguments to be print.
 *
 * Return: return value  Precision.
 */

int get_size(const char *format, int *p)
{
	int curr_p = *p + 1;
	int si = 0;

	if (format[curr_p] == 'l')
		si = S_LONG;
	else if (format[curr_p] == 'h')
		si = S_SHORT;

	if (si == 0)
		*p = curr_p - 1;
	else
		*p = curr_p;

	return (si);
}
