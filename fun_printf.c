#include "holberton.h"
#include <unistd.h>
static int count;
int func_bin(unsigned int a, char *p);
int func_uint(unsigned int a, char *p);
int func_oct(unsigned int a, char *p);
int func_hex(unsigned int a, char *p);
int func_HEX(unsigned int a, char *p);
int func_r(char *c, char *p);

/**
 * func_int - Prints an integer
 * @a: The number
 * @p: Pointer to derefrence decimals
 * Return: Length of number
 */
int func_int(int a, char *p)
{
	if (a < 0)
	{
		p[count++] = '-';
		a = -a;
	}
/* Remove the last digit and recur */
	if (a / 10)
		func_int(a / 10, p);
/* Print the last digit */
	p[count++] = (a % 10 + '0');
	return (count);
}
/*
int func_p(char **c, char *p)
{
	int i;

	for (i = 0; i< 16; i++)
		*(p + i) = c[i];
	return (16);

}
*/



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
				count = 0;
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
/*			case 'p':
				j = j + func_p((char *)va_arg(v_list, void *), array + j);
				break; */
			case 'R':
				j = j + func_R(va_arg(v_list, char *), array + j);
			default:
				return (-1);
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
	va_end(v_list);
	return (j);
}
