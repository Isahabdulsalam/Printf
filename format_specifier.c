#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _spec(const char *format, ...) {

    int num = 0;
    int count = 0;
	va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i')) {
            num = va_arg(args, int);
            printf("%d", num);
            count++;
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

