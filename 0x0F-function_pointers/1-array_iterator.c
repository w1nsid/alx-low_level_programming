#include "function_pointers.h"

/**
 * array_iterator - Executes a function given as a parameter on each element
 * @array: Array of integers
 * @size: Size of the array
 * @action: Pointer to the function you need to use
 *
 * Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i = 0;

	if (array != NULL && action != NULL && size > 0)
	{
		while (i < size)
		{
			action(array[i]);
			i++;
		}
	}
}
