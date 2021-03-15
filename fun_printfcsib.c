static int count;
/**
 * func_c - Prints one character
 * @a: input character
 * @p: pointer
 */
void func_c(int a, char *p)
{
	*p = a;
}
/**
 * func_s - Prints string
 * @c: Input string
 * @p: Pointer
 * Return: Length of string
 */
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
/**
 * func_bin - Print a base 10 in binary
 * @a: The input number
 * @p: The pointer
 * Return: Length of number
*/
int func_bin(unsigned int a, char *p)
{
	count = 0;
	/* Remove the last digit and recurse */
	if (a / 2)
		func_bin(a / 2, p);
	/* Print the last digit */
	p[count++] = (a % 2 + '0');
	return (count);
}
