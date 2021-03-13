#include "holberton.h"
#include <unistd.h>
static int count;
/**
 *  - Entry point
 *
 * Return: Always 0
 */

/* Prints one character*/
void func_c(int a, char * p)
{
    *p = a;
}
/* Prints string*/
int func_s(char *c, char *p)
{
    int i = 0;
    
    while (c[i])
    {
        p[i] = c[i];
        i++;
    }
    return (i);
}
/* Prints % symbol
void func_pct()
{
	_putchar('%');
}
 No specifier
void func_default()
{
}
 Prints an integer*/
int func_int(int a, char *p)
{    
    if (a < 0) {
        p[count++] = '-';
        a = -a;
    }
    /* Remove the last digit and recur */
    if (a/10)
        func_int(a/10, p);
    /* Print the last digit */
    p[count++] = (a%10 + '0');
    
    return (count);
}
	/* Remove the last digit and recur */
	/* Print the last digit */
/* Print a base 10 in binary
void func_bin(unsigned int a)
{
	 Remove the last digit and recur 
	if (a/2)
		func_bin(a/2);
	 Print the last digit 
	_putchar(a%2 + '0');
}
 Print unsigned int 
void func_uint(unsigned int a)
{
	// Remove the last digit and recur
	if (a/10)
		func_uint(a/10);
	// Print the last digit
	_putchar(a%10 + '0');
}
 Prints unsigned int to octal
void func_oct(unsigned int a)
{
	// Remove the last digit and recur
	if (a/8)
		func_oct(a/8);
	// Print the last digit
	_putchar(a%8 + '0');
}
 Prints unsigned int to abcdef hex
void func_hex(unsigned int a)
{
	// Remove the last digit and recur
	if (a/16)
		func_hex(a/16);
	// Print the last digit
	if (a%16 <=9)
	_putchar(a%16 + '0');
	else
		_putchar(a%16 - 10 + 'a');
}
 Prints unsigned int to ABCDEF hex
void func_HEX(unsigned int a)
{
	// Remove the last digit and recur
	if (a/16)
		func_HEX(a/16);
	// Print the last digit
	if (a%16 <=9)
		_putchar(a%16 + '0');
	else
		_putchar(a%16 - 10 + 'A');
}

Loop to check for specifiers. If not specifier, putchar character */
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
			/* Switch statement to pick function for specifier*/
			switch (format[i + 1])
			{
				case 'c':
					func_c(va_arg(v_list, int), array + j++);
					break;
				case 's':
					j = j + func_s(va_arg(v_list, char *), array + j);
					break;
/*				case '%':
					func_pct();
					break;*/
			case 'd':
			case 'i':
				count = 0;
                    		j = j + func_int(va_arg(v_list, int), array + j);
				break;
/*			case 'b':
				func_bin(va_arg(v_list, unsigned int));
				break;
			case 'u':
				func_uint(va_arg(v_list, int));
				break;
			case 'o':
				func_oct(va_arg(v_list, unsigned int));
				break;
			case 'x':
				func_hex(va_arg(v_list, unsigned int));
				break;
			case 'X':
				func_HEX(va_arg(v_list, unsigned int));
				break;
				default:
					func_pct();
					break;*/
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
	_printf("abcd%c %s %i %d", 'H', "Holberton", 98, -98);
	return (0);
}
