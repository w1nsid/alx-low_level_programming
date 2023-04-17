#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees dogs from memory
 * @d: pointer to dog
 *
 * Return: Nothing
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->owner);
		free(d->name);
		free(d);
	}
}
