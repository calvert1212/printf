static int count;
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
	if (a / 10)
		func_uint(a / 10, p);
	/* Print the last digit */
	p[count++] = (a % 10 + '0');
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
	if (a / 8)
		func_oct(a / 8, p);
	/* Print the last digit */
	p[count++] = (a % 8 + '0');
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
	if (a / 16)
		func_hex(a / 16, p);
	/* Print the last digit */
	if (a % 16 <= 9)
		p[count++] = (a % 16 + '0');
	else
		p[count++] = (a % 16 - 10 + 'a');
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
	if (a / 16)
		func_HEX(a / 16, p);
	/* Print the last digit */
	if (a % 16 <= 9)
		p[count++] = (a % 16 + '0');
	else
		p[count++] = (a % 16 - 10 + 'A');
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
	l = l - 1;
	while (l >= 0)
	{
		p[x] = c[l];
		l--;
		x++;
	}
	return (i);
}
