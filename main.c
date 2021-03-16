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
	_printf("%%%k %s %s %c %c\n", s,s1,c1,c2);
	_printf("%%%k %s %s %c %c\n", s,s1,c1,c2);





	return (0);
}
