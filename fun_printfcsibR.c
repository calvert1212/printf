static int count = 0;
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
/**
 * func_R - Prints string in rot 13 encryption
 * @a: The input string
 * @p: The pointer
 * Return: Length of the string
 */
int func_R(char *c, char *p)
{
	int i = 0;

	while (c[i])
	{
		if ((c[i] >= 'a' && c[i] <= 'm') || (c[i] >= 'A' && c[i] <= 'M'))
			p[i] = (c[i] + 13);
		else if((c[i] >= 'n' && c[i] <= 'a') || (c[i] >= 'N' && c[i] <= 'Z'))
			p[i] = (c[i] - 13);
		else
			p[i] = c[i];
		i++;
	}
	return (i);
}
