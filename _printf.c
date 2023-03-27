<<<<<<< HEAD
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
=======
#include <stdarg.h>   /* va_list, va_start, va_arg */
#include <unistd.h>   /* write */
#include <string.h>	
>>>>>>> df6bf12ac8eb9f61c732dfa62e6a0080c5cee23b

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
<<<<<<< HEAD
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
	int count = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* skip % */
			switch (*format)
			{
				case 'c':
					count += write(1, va_arg(args, int), 1);
					break;
				case 's':
					count += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%", 1);
					count += write(1, &(*format), 1);
					break;
			}
		}
		else
		{
			count += write(1, &(*format), 1);
		}
		format++;
	}

	va_end(args);
	return count;
>>>>>>> df6bf12ac8eb9f61c732dfa62e6a0080c5cee23b
}
