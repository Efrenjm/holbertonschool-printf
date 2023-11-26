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

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *)) - 1;
					break;
				case '%':
					putchar('%');
					break;
				default:
					printf('\%%%s', *format);
					count++;
					break;
			}
			count++;
		}
		else if (*format == '%' && *(format + 1) == '\0')
		{
			return (-1);
		}
		else
		{
			putchar(*format);
			count++;
		}
	}
	va_end(args);
	return (count);
}
