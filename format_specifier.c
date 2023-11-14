#include "main.h"
#include <stdarg.h>

int _spec(const char *format, ...)
{
	int count = 0;
	va_list argument;
	va_start(argument, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int word = va_arg(argument, int);
				printf("%d", word);
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(argument);
	return (count);
}
