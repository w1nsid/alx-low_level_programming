#include "main.h"

/**
 * create_file - create a file.
 * @filename: A pointer to the name of the file to create.
 * @content: A pointer to the string to write to the file.
 *
 * Return: If the function fails - -1, otherwise - 1.
 */
int create_file(const char *filename, char *content)
{
	int file_descriptor, bytes_written, length = 0;

	if (filename == NULL)
		return (-1);

	if (content != NULL)
	{
		for (length = 0; content[length];)
			length++;
	}

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	bytes_written = write(file_descriptor, content, length);

	if (file_descriptor == -1 || bytes_written == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}
