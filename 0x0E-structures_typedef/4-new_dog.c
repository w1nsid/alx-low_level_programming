#include <stdlib.h>
#include "dog.h"

int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/**
 * new_dog - Creates a new dog
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 *
 * Return: Pointer to new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog_ptr;
	int name_size = 0;
	int owner_size = 0;

	if (name != NULL && owner != NULL)
	{
		name_size = _strlen(name) + 1;
		owner_size = _strlen(owner) + 1;
		dog_ptr = malloc(sizeof(dog_t));
		/*
		 * If malloc fails, return NULL
		 */
		if (dog_ptr == NULL)
			return (NULL);

		dog_ptr->name = malloc(sizeof(char) * name_size);

		/*
		 * If malloc fails, free the memory allocated for the dog
		 * and return NULL
		 */
		if (dog_ptr->name == NULL)
		{
			free(dog_ptr);
			return (NULL);
		}

		dog_ptr->owner = malloc(sizeof(char) * owner_size);

		/*
		 * If malloc fails, free the memory allocated for the dog
		 * and return NULL
		 */
		if (dog_ptr->owner == NULL)
		{
			free(dog_ptr->name);
			free(dog_ptr);
			return (NULL);
		}

		_strcpy(dog_ptr->name, name);
		dog_ptr->age = age;
		_strcpy(dog_ptr->owner, owner);
	}

	return (dog_ptr);
}

/**
 * _strlen - Returns the length of a string
 * @s: String to count
 *
 * Return: String length
 */
int _strlen(char *s)
{
	int c = 0;

	for (; *s != '\0'; s++)
	{
		c++;
	}

	return (c);
}

/**
 * _strcpy - Copy a string
 * @dest: Destination value
 * @src: Source value
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i++] = '\0';

	return (dest);
}
