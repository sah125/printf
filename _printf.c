#include <stdarg.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function with custom conversion specifier %b
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int i, j, printed = 0, printed_chars = 0;
    int buff_ind = 0, n, base = 2, rem;
    char buffer[BUFF_SIZE];
    unsigned int num;

    va_list list;

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
            printed_chars++;
        }
        else
        {
            i++; /* skip '%' */

            switch (format[i])
            {
                case 'b':
                    num = va_arg(list, unsigned int);
                    j = 0;
                    while (num != 0)
                    {
                        rem = num % base;
                        num /= base;
                        buffer[buff_ind + j] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
                        j++;
                    }
                    buff_ind += j;
                    break;

                default:
                    buffer[buff_ind++] = '%';
                    buffer[buff_ind++] = format[i];
                    break;
            }

            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);

            printed_chars++;
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);

    return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, &buffer[0], *buff_ind);
        *buff_ind = 0;
    }
}
}
