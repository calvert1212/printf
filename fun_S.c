void print_hexval(int d, char *p)
{
	int i = 0;

	p[i] = '\\';
	p[i + 1] = 'x';

	if (d / 16 <= 9)
		p[i + 2] = (d / 16 + '0');
	else
		p[i + 3] = (d / 16 - 10 + 'A');
	if (d % 16 <= 9)
		p[i + 3] = (d % 16 + '0');
	else
		p[i + 3] = (d % 16 - 10 + 'A');
}

/**
 *
 *@c: point to the starting address of the argument string passed in
 *@p: points at address in buffer array to start push the character
*/
int func_S(char *c, char *p)
{
	int i = 0;
	int j = 0;

	while (c[i])
	{
			switch (c[i])
			{
				case '\n':
					print_hexval(10, p + j);
					j = j + 4;
					break;
				case '\\':
					print_hexval(92, p + j);
					j = j + 4;
					break;
			case '\a':
				print_hexval(7, p + j);
				j = j + 4;
				break;
				case '\b':
					print_hexval(8, p + j);
					j = j + 4;
					break;
				case '\f':
					print_hexval(12, p + j);
					j = j + 4;
					break;
				case '\r':
					print_hexval(13, p + j);
					j = j + 4;
					break;
				case '\t':
					print_hexval(9, p + j);
					j = j + 4;
					break;
				case '\v':
					print_hexval(11, p + j);
					j = j + 4;
					break;
				default:
					p[j] = c[i];
					j = j + 1;
					break;
			}
			i++;
	}
	return (j);
}
