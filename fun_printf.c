#include "holberton.h"
/**
 *  - Entry point
 *
 * Return: Always 0
 */

/* Prints one character*/
void func_c(int a)
{
	_putchar(a);

}
/* Prints string*/
void func_s(char *c)
{
	int i = 0;
	
	while (c[i])
	{
		_putchar(c[i]);
		i++;
	}
}
/* Prints % symbol*/
void func_pct()
{
	_putchar('%');
}
/* No specifier*/
void func_default()
{
}

/* Loop to check for specifiers. If not specifier, putchar character */
int _printf(const char *format, ...)
{
	va_list v_list;
	int i = 0;

	va_start(v_list, format);	
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			/* Switch statement to pick function for specifier*/
			switch (format[i + 1])
			{
				case 'c':
					func_c(va_arg(v_list, int));
					break;
				case 's':
					func_s(va_arg(v_list, char *));
					break;
				case '%':
					func_pct();
					break;
				default:
					func_pct();
					break;
			}
		i += 1;
		}
		else
			_putchar(format[i]);
		i++;
	}
	return (0);
}
int main ()
{
	_printf("%ca%%b%zcd%sefg",'O',"THIS IS A STRING");

	return (0);
}
