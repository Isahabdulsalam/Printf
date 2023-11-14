#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function to produce output
 * @format: Character String
 * Return: number of character
 */

int _printf(const char *format, ...) {
	int count = 0;
	va_list argument;
	va_start(argument, format);

	while (*format != '\0') 
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c') 
			{
				int character = va_arg(argument, int);
				putchar(character);
				count++;
			}
			else if (*format == 's')
			{
				const char *string = va_arg(argument, const char*);
				while (*string != '\0') 
				{
					putchar(*string);
					string++;
					count++;
				}
			}
			else if (*format == '%') 
			{
				putchar('%');
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
	return count;
}
