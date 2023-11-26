#include <stdio.h>
#include <stdarg.h>

void helper(const char specifier, va_list args, int *count)
{
                        switch (specifier)
                        {
                                case 'c':
                                        putchar(va_arg(args, int));
                                        break;
                                case 's':
                                        *count += printf("%s", va_arg(args, char *)) - 1;
                                        break;
                                case '%':
                                        putchar('%');
                                        break;
                                default:
                                        putchar("%");
					putchar(specifier)
                                        (*count)++;
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
			helper(*format,args,&count);
			/*format++;
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
					printf("%%s", *format);
					count++;
					break;
			}*/
		}
		else if (*format == '%' && *(format + 1) == '\0')
		{
			return (-1);
		}
		else
			putchar(*format);
		count++;
		format++;
	}
	printf("\n");
	va_end(args);
	return (count);
}
