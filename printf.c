#include <stdio.h>
#include <stdarg.h>
/**
 * helper - format selector
 * @specifier: char to specify format
 * @args: list of variadic arguments
 * @count: pointer to the counter
 * Return: none
 */
void helper(const char specifier, va_list args, int *count)
{
	switch (specifier)
	{
		case 'c':
			putchar(va_arg(args, int));
			(*count)++;
			break;
		case 's':
			*count += printf("%s", va_arg(args, char *));
			break;
		case '%':
			putchar('%');
			(*count)++;
			break;
		default:
			putchar('%');
			putchar(specifier);
			(*count) += 2;
			break;
	}
}
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
			helper(*format, args, &count);
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
