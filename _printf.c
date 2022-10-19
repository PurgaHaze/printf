#include <stddef.h>
#include "main.h"
/**
 * _prinf - Copy the function of orignal prinf
 * @format: format string
 * Return :The value of printed char
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int sum = 0, i = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = get_op(format[i + 1]);
			if (func == NULL)
			{
				putchar(format[i]);
				sum++;
				i++;
			}
			else
			{
				sum += func(ap);
				i += 2;
				continue;
			}
		}
		else
		{


			putchar(format[i]); 
			sum++;
			i++;
		}
	}
	va_end(ap);
	return (sum);
}
