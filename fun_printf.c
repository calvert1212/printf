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
/*Print a base 10 in binary*/
int func_bin(unsigned int a, char *p)
{
	count = 0;
	/*Remove the last digit and recur*/
		 if (a/2)
			 func_bin(a/2, p);
		 /*Print the last digit*/ 
	p[count++] = (a%2 + '0');
	return (count);
}

//Print unsigned int
int func_uint(unsigned int a, char *p)
{
	count = 0;
	// Remove the last digit and recur
	if (a/10)
		func_uint(a/10, p);
	// Print the last digit
	p[count++] = (a%10 + '0');
	return (count);
}

//Prints unsigned int to octal
int func_oct(unsigned int a, char *p)
{
	count = 0;
	// Remove the last digit and recur
	if (a/8)
		func_oct(a/8, p);
	// Print the last digit
	p[count++] = (a%8 + '0');
	return (count);
}
//Prints unsigned int to abcdef hex
int func_hex(unsigned int a, char *p)
{
	count = 0;
	// Remove the last digit and recur
	if (a/16)
		func_hex(a/16, p);
	// Print the last digit
	if (a%16 <=9)
	p[count++] = (a%16 + '0');
	else
		p[count++] = (a%16 - 10 + 'a');
	return (count);
}
//Prints unsigned int to ABCDEF hex
int func_HEX(unsigned int a, char *p)
{
	count = 0;
	// Remove the last digit and recur
	if (a/16)
		func_HEX(a/16, p);
	// Print the last digit
	if (a%16 <=9)
		p[count++] = (a%16 + '0');
	else
		p[count++] = (a%16 - 10 + 'A');
	return (count);
}

/*Loop to check for specifiers. If not specifier, putchar character */
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
		// Switch statement to pick function for specifier
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
	_printf("abcd%c %s %i %o %x %X", 'H', "Holberton", -98, 98, 15, 15);
	return (0);
}
