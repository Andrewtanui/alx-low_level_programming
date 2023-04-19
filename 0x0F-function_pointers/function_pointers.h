#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/*
 * desc: Header file that contains prototypes for all functions
 * 	 used in 0x0F-function_pointers directory
 */

#include <stdlib.h>

void print_name(char *name, void (*f)(char *));
#endif
