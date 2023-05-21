/**
 * get_bit - gets the value of a bit at index,
 * starting from least significant bit at 0
 *
 * @num: number to get bit from
 * @bitIndex: index of the bit
 *
 * Return: value of the bit, or -1 if error
 */
int get_bit(unsigned long int num, unsigned int bitIndex)
{
	unsigned long int bitmask;

	if (bitIndex > 63)
		return (-1);

	bitmask = 1 << bitIndex;
	return ((num & bitmask) > 0);
}
