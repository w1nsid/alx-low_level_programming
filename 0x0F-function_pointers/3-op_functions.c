#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * op_add - Adds two integers
 * @a: integer to add
 * @b: integer to add
 *
 * Return: The result of the addition
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Subtracts two integers
 * @a: integer to subtract
 * @b: integer to subtract
 *
 * Return: The result of the subtraction
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiplies two integers
 * @a: integer to multiply
 * @b: integer to multiply
 *
 * Return: The result of the multiplication
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Divides two integers
 * @a: integer to divide
 * @b: integer to divide
 *
 * Return: The result of the division
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
 * op_mod - Computes the remainder of the division of two integers
 * @a: Integer to divide
 * @b: Integer to divide
 *
 * Return: The remainder of the division
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
