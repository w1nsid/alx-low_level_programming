#include "main.h"
/**
 * clear_bit - Clears the value of a bit at a given index to 0
 * @num: Pointer to the input number
 * @bitIndex: Index of the bit to clear
 * Return: 0 on success, or -1 if error
 */
int clear_bit(unsigned long int *num, unsigned int bitIndex)
{
	if (bitIndex >= 64)
		return (-1);

	*num = *num & ~(1ul << bitIndex);
	return (1);
}
