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
int len;

/*len = _printf("%\n");
printf("%d\n", len);
len = printf("%\n");
printf("%d\n", len);

len = printf("%\n");
printf("%d\n", len);
len = printf("%");
printf("%d\n", len);*/

                                                                                   
/*_printf("%%d");                                                                                   
_printf("%");                                                                                    
_printf("%%%d", 10);                                                                           
_printf("%\n");                                                                                  
_printf("%%");                                                                                    
_printf("% ");                                                                                    
_printf(" %");*/                                                                                     
len = printf("hello% ");
printf("1. %d\n", len);                                                                               
len = printf("hello% [] ");
printf("2. %d\n", len);                                                                           
len = printf(" hello% ");
printf("3. %d\n", len);                                                                               
len = printf(" hello% [] ");
printf("4. %d\n", len);                                                                         

	return (0);
}
