#include <unistd.h>

/**
 * _putchar - Write a character to stdout
 */

int _putchar(char c)
{
    return write(STDOUT_FILENO, &c, 1);
}
