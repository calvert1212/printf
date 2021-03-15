#include "holberton.h"
#include <unistd.h>
/**
 * _printf - Primary function: Writes characters and looks for specifiers etc.
 * @format: Arguments given as strings
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	va_list v_list;
	int i = 0, j = 0;
	char array[1024];

	va_start(v_list, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					func_c(va_arg(v_list, int), array + j++);
					break;
				case 's':
					j = j + func_s(va_arg(v_list, char *), array + j);
					break;
				case '%':
					array[j] = ('%');
					j++;
					break;
			case 'd':
			case 'i':
				j = j + func_int(va_arg(v_list, int), array + j);
				break;
			case 'b':
				j = j + func_bin(va_arg(v_list, unsigned int), array + j);
				break;
			case 'u':
				j = j + func_uint(va_arg(v_list, int), array + j);
				break;
			case 'o':
				j = j + func_oct(va_arg(v_list, unsigned int), array + j);
				break;
			case 'x':
				j = j + func_hex(va_arg(v_list, unsigned int), array + j);
				break;
			case 'X':
				j = j + func_HEX(va_arg(v_list, unsigned int), array + j);
				break;
			case 'S':
				j = j + func_S(va_arg(v_list, char *), array + j);
				break;
			case 'r':
				j = j + func_r(va_arg(v_list, char *), array + j);
			}
			i += 1;
		}
		else
		{
			array[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, &array, j);
	return (j);
}
