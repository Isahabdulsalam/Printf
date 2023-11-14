#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list argument;
    va_start(argument, format);

    int count = 0;
    while (*format != '\0') 
    {
        if (*format == '%') 
	{
            format++;
            if (*format == 'c') 
	    {
                int character = va_arg(argument, int);
                _putchar(character);
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
                _putchar('%');
                count++;
            }
        }
        else 
	{
            _putchar(*format);
            count++;
        }
        format++;
    }

    va_end(argument);
    return count;
}
