#include "main.h"
/**
 * set_bit - Sets the value of a bit at a given index to 1
 * @num: Pointer to the input number
 * @bitIndex: Index of the bit to set
 * Return: 0 on success, or -1 if error
 */
int set_bit(unsigned long int *num, unsigned int bitIndex)
{
	if (bitIndex > 63)
		return (-1);

	*num = *num | 1ul << bitIndex;
	return (1);
}
