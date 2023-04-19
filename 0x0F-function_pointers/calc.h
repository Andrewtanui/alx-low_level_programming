#ifndef CALC_H
#define CALC_H

/*
 * Desc: Header file containing prototypes for all functions
 *       used in the 3-main.c program.
 */

/**
 * struct op - A struct operator.
 * @op: The operator.
 * @f: Associated function.
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);

#endif
