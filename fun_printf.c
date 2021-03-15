#include "holberton.h"
#include <unistd.h>
/**
 * func_uint - Print unsigned int
 * @a: The input number
 * @p: The pointer
 * Return: Length of the number
 */
int func_uint(unsigned int a, char *p)
{
	count = 0;
	/* Remove the last digit and recur*/
	if (a/10)
		func_uint(a/10, p);
	/* Print the last digit */
	p[count++] = (a%10 + '0');
	return (count);
}

/**
 * func_oct - Prints unsigned int to octal
 * @a: The input number
 * @p: The pointer
 * Return: Length of the number
 */
int func_oct(unsigned int a, char *p)
{
	count = 0;
	/* Remove the last digit and recur */
	if (a/8)
		func_oct(a/8, p);
	/* Print the last digit */
	p[count++] = (a%8 + '0');
	return (count);
}

/**
 * func_hex - Prints unsigned int to abcdef hex
 * @a: The input number
 * @p: The pointer
 * Return: Length of the number
 */
int func_hex(unsigned int a, char *p)
{
	count = 0;
	/* Remove the last digit and recur */
	if (a/16)
		func_hex(a/16, p);
	/* Print the last digit */
	if (a%16 <=9)
	p[count++] = (a%16 + '0');
	else
		p[count++] = (a%16 - 10 + 'a');
	return (count);
}

/**
 * func_HEX Prints unsigned int to ABCDEF hex
 * @a: The input number
 * @p: The pointer
 * Return: The length of the number
 */
int func_HEX(unsigned int a, char *p)
{
	count = 0;
	/* Remove the last digit and recur */
	if (a/16)
		func_HEX(a/16, p);
	/* Print the last digit */
	if (a%16 <=9)
		p[count++] = (a%16 + '0');
	else
		p[count++] = (a%16 - 10 + 'A');
	return (count);
}

/**
 * func_p - Prints input string in reverse
 * @c: Input string
 * @p: The pointer
 * Return: Length of the reverse string
 */
int func_r(char *c, char *p)
{
	int i, l, x = 0;

	while (c[i])
	{
		i++;
	l++;
	}
	l = l -1;
	while (l >= 0)
	{
		p[x] = c[l];
		l--;
		x++;
	}
	return (i);
}

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
		/* Switch statement to pick function for specifier */
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

				/*default:
					func_pct();
					break;
				*/
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
	write(1, &array,j);
	return (0);
}
int main ()
{
	_printf("abcd");
	return (0);
}
