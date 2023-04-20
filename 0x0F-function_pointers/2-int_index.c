#include "function_pointers.h"

/**
 * int_index - Searches for an integer
 * @array:  Array of integers
 * @size:  Size of the array
 * @cmp:  Pointer to the function you need to use
 *
 * Return:  The index of the first element for which the cmp function does not
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (i < size)
			{
				if (cmp(array[i]))
					return (i);

				i++;
			}
		}
	}

	return (-1);
}
