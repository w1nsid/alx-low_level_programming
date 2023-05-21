#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *file);
void close_file(int fd);

/**
 * allocate_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file the buffer is storing chars for.
 *
 * Return: A pointer to the newly allocated buffer.
 */
char *allocate_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int status;

	status = close(fd);

	if (status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int src_file, dest_file, read_status, write_status;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[2]);
	src_file = open(argv[1], O_RDONLY);
	read_status = read(src_file, buffer, 1024);
	dest_file = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do
	{
		if (src_file == -1 || read_status == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_status = write(dest_file, buffer, read_status);
		if (dest_file == -1 || write_status == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_status = read(src_file, buffer, 1024);
		dest_file = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_status > 0);

	free(buffer);
	close_file(src_file);
	close_file(dest_file);

	return (0);
}
