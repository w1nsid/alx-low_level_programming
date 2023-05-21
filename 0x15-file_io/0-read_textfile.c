#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - read textfile print to stdout
 * @filename: text file being read
 * @letters: number of letters
 * Return: w- actual number
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fileDescriptor;
	ssize_t bytesRead;
	ssize_t bytesWritten;

	fileDescriptor = open(filename, O_RDONLY);
	if (fileDescriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	bytesRead = read(fileDescriptor, buffer, letters);
	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

	free(buffer);
	close(fileDescriptor);

	return (bytesWritten);
}
