#include "holberton.h"
/**
 *  - Entry point
 *
 * Return: Always 0
 */
void func_c(a)
{
	_putchar(a);

}

void func_s(char *c)
{
	int i = 0;
	
	while (c[i])
	{
		_putchar(c[i]);
		i++;
	}
}
void func_pct()
{
	_putchar('%');
}
void func_default(int a)
{
}

int _printf(const char *format, ...)
{
	va_list v_list;
	int i = 0;

	va_start(v_list, format);	
	while (format && format[i])
	{
		if (format[i] == '%')
		{
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
					func_default(va_arg(v_list, int));
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
	_printf("%ca%%bcd%sefg",'O',"THIS IS A STRING");

	return (0);
}
