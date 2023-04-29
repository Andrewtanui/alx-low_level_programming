#include <stdio.h>

/**
 * turtle_before_main - prints a message before main is executed
 */
void __attribute__ ((constructor)) turtle_before_main()
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
