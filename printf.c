#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - function to emulate printf
 * @format: character string
 * Return: the number of characters
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	if (*format == NULL)
		return (0);

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else if (*format == '%' && *(format + 1) == '\0')
		{
			return (0);
                }
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
