#include <limits.h>
#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char c1 = 'H';
	char *s = "I am a string";
	char *s1 = "";
	char c2 = NULL;



/*	_printf("%%% %s%s%c%c", s,s1,c1,c2); */
	_printf("s1 is a empty and it is [%s], s is a string [%s] c1 is a char [%c] c2 is null char [%c]\n", s1,s,c1,c2);
	printf("%%  wdwfa %s %s %c %c\n", s,s1,c1,c2);

	_printf("%d %d", INT_MIN, INT_MAX);





	return (0);
}
