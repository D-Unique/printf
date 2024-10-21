#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * _print - this function immetates printf function
 * @format: the args
 * Return: a buffer to the stdout
 **/



int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int buffer_index;
	int i = 0;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{

		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				buffer[buffer_index] = va_arg(args, int);
				buffer_index++;
				break;
			case 's':
			{
				const char *str = va_arg(args, const char *);

				while (*str != '\0')
				{
					buffer[i] = *str;
					i++;
					str++;
				}
				break;
			}
			case '%':
			buffer[buffer_index] = '%';
			buffer_index++;
			break;
			}
		}
		else
		{
			buffer[buffer_index] = format[i];
			buffer_index++;
		}
	}
	va_end(args);
	return (write(1, buffer, buffer_index));
}
