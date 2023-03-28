#include <stdarg.h>   /* va_list, va_start, va_arg */
#include <unistd.h>   /* write */
#include <string.h>	

	/**
	 * _printf - produces output according to a format.
	 * @format: format string.
	 * Return: number of characters printed.
	 */
	int _printf(const char *format, ...)
	{
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
	                    count += write(1, va_arg(args, int, 1);
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
}
