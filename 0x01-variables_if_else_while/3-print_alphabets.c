#include <stdio.h>

/**
 *main - print lowercase and uppercase a-zA-Z using putchar
 *Return: Always 0 (Success)
 */

int main(void)
{
	char c = 'a';
	char C = 'A';

	while (c <= 'z') /*print lowercases a-z*/
	{
		putchar(c);
		c++;
	}

	while (C <= 'Z') /*print uppercase A-Z*/
	{
		putchar(C);
		C++;
	}

	putchar('\n');

	return (0);
}
