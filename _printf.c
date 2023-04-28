#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**

_printf - A custom implementation of printf function

@format: The format string.

Return: The number of printed characters.
*/
int _printf(const char *format, ...)
{
int i, printed_chars = 0, flags, width, precision, size, buff_ind = 0;
int printed = 0;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
{
print_buffer(buffer, &buff_ind);
}
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
i++;
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
{
va_end(list);
return (-1);
}
printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);

va_end(list);

return (printed_chars);
}

/**

print_buffer - Helper function to print the contents of the buffer

@buffer: Array of chars

@buff_ind: Index at which to add next char, represents the length.
*/
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
{
write(1, &buffer[0], *buff_ind);
}

*buff_ind = 0;
}