#include "../main.h"
#include <stdio.h>

int main(void)
{
	char *null = NULL;
	char c = 'a';
	char s[] = "testing printf";
	int counter = 0;

	/* counter result will be +1 because of '\n' */

	counter = _printf("test1\n");
	printf("character printed: %d\n", counter);
	counter = _printf("%c\n", c);
	printf("character printed: %d\n", counter);
	counter = _printf("%s\n", s);
	printf("character printed: %d\n", counter);
	counter = _printf("%s\n", null);
	printf("character printed: %d\n", counter);
	counter = _printf("");
	printf("character printed: %d\n", counter);
	return (0);
}
