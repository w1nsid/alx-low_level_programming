#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *ident);
void print_magic(unsigned char *ident);
void print_class(unsigned char *ident);
void print_data(unsigned char *ident);
void print_version(unsigned char *ident);
void print_abi(unsigned char *ident);
void print_osabi(unsigned char *ident);
void print_type(unsigned int type, unsigned char *ident);
void print_entry(unsigned long int entry, unsigned char *ident);
void close_elf(int fd);

/**
 * check_elf - Checks if a file is an ELF file.
 * @ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description:
 * This function checks the magic numbers in the ELF identification
 * array. If the file is not an ELF file, it exits with code 98.
 */

void check_elf(unsigned char *ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (ident[index] != 127 &&
			ident[index] != 'E' &&
			ident[index] != 'L' &&
			ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers from the ELF identification array.
 * @ident: A pointer to an array containing the ELF identification information.
 *
 * Description:
 * This function prints the magic numbers represented as hexadecimal
 * values from the given identification array. The magic numbers
 * provide information about the file format. Each number is printed
 * as a two-digit hexadecimal value. The function adds a space
 * between the numbers and ends the line after printing all of them.
 */

void print_magic(unsigned char *ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the ELF class information.
 * @ident: A pointer to an array containing the ELF identification information.
 *
 * Description:
 * This function prints the class of the ELF file format. The class
 * represents the architecture-specific data organization used by
 * the file. It can be one of the following:
 * - ELFCLASSNONE: No class specified.
 * - ELFCLASS32:   32-bit ELF file format.
 * - ELFCLASS64:   64-bit ELF file format.
 * If the class is unknown, it is printed as "<unknown: %x>",
 * where %x represents the hexadecimal value of the class.
 * The function provides this information as part of the formatted
 * output with proper alignment.
 */

void print_class(unsigned char *ident)
{
	printf("  Class:                             ");

	switch (ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints the ELF data encoding information.
 * @ident: A pointer to an array containing the ELF identification information.
 *
 * Description:
 * This function prints the data encoding of the ELF file format.
 * The data encoding specifies the byte order used for data
 * representation in the file. It can be one of the following:
 * - ELFDATANONE:             Unknown data encoding.
 * - ELFDATA2LSB:             Two's complement, little endian.
 * - ELFDATA2MSB:             Two's complement, big endian.
 * If the data encoding is unknown, it is printed as "<unknown: %x>",
 * where %x represents the hexadecimal value of the data encoding.
 * The function provides this information as part of the formatted
 * output with proper alignment.
 */

void print_data(unsigned char *ident)
{
	printf("  Data:                              ");

	switch (ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}

/**
 * print_version - Prints the ELF version information.
 * @ident: A pointer to an array containing the ELF identification information.
 *
 * Description: This function prints the version of the ELF file format.
 *              The version represents the ELF header version number. It is
 *              an 8-bit value stored in the ELF identification array.
 *              The function prints the version number as part of the formatted
 *              output, with proper alignment. If the version is EV_CURRENT,
 *              it is printed as " (current)" following the version number.
 *              Otherwise, it is printed as a standalone value.
 */

void print_version(unsigned char *ident)
{
	printf("  Version:                           %d",
		   ident[EI_VERSION]);

	switch (ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints the OS/ABI information of an ELF file.
 * @ident: A pointer to an array containing the ELF identification information.
 *
 * Description: This function prints the OS/ABI (Operating System/Application
 *              Binary Interface) information of the ELF file. The OS/ABI
 *              represents the target operating system and ABI used by the ELF
 *              file. It is an 8-bit value stored in the ELF identification
 *              array.
 *
 *              The function uses a switch statement to match the OS/ABI value
 *              and prints the corresponding description. If the OS/ABI is
 *              recognized, it is printed in the format "UNIX - <Description>".
 *              If the OS/ABI is not recognized, it is printed as "<unknown>"
 *              followed by the hexadecimal value of the OS/ABI.
 */

void print_osabi(unsigned char *ident)
{
	printf("  OS/ABI:                            ");

	switch (ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", ident[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI version of an ELF file.
 * @ident: A pointer to an array containing the ELF identification information.
 *
 * Description: This function prints the ABI (Application Binary Interface)
 *              version of the ELF file. The ABI version is an 8-bit value
 *              stored in the ELF identification array. It represents the
 *              version of the ABI used by the ELF file.
 *
 *              The function simply prints the ABI version value followed by a
 *              newline character.
 */

void print_abi(unsigned char *ident)
{
	printf("  ABI Version:                       %d\n",
		   ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF file.
 * @type: The type value of the ELF file.
 * @ident: A pointer to an array containing the ELF identification information.
 *
 * Description: This function prints the type of the ELF file. The type value
 *              represents the category or purpose of the file, such as whether
 *              it is a relocatable file, executable file, shared object file,
 *              or core file.
 *
 *              The function first checks the endianness of the file based on
 *              the identification information. If the file is big-endian, it
 *              adjusts the type value by shifting it right by 8 bits. Then, it
 *              prints the corresponding type string based on the type value.
 *
 *              The type string is printed along with its description in
 *              parentheses, followed by a newline character.
 */

void print_type(unsigned int type, unsigned char *ident)
{
	if (ident[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}

/**
 * print_entry - Prints the entry point address of an ELF file.
 * @entry: The entry point address value of the ELF file.
 * @ident: A pointer to an array containing the ELF identification information.
 *
 * Description: This function prints the entry point address of the ELF file.
 *              The entry point address represents the memory address where the
 *              execution of the program starts when the ELF file is executed.
 *
 *              The function first checks the endianness of the file based on
 *              the identification information. If the file is big-endian, it
 *              adjusts the entry point address by swapping the byte order.
 *
 *              The function then determines the class of the ELF file (32-bit
 *              or 64-bit) based on the identification information. It prints
 *              the entry point address in hexadecimal format with the correct
 *              format specifier (%#x for 32-bit and %#lx for 64-bit), followed
 *              by a newline character.
 */

void print_entry(unsigned long int entry, unsigned char *ident)
{
	printf("  Entry point address:               ");

	if (ident[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
				((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);
	else
		printf("%#lx\n", entry);
}

/**
 * close_elf - Closes the file descriptor associated with an ELF file.
 * @fd: The file descriptor to be closed.
 *
 * Description: This function closes the file descriptor that was opened for
 *              accessing an ELF file. If an error occurs while closing the
 *              file descriptor, it prints an error message to the standard
 *              error stream and exits the program with exit code 98.
 */

void close_elf(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close file descriptor %d\n", fd);
		exit(98);
	}
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: Always 0.
 *
 * Description:
 * This function is the entry point of the program. It reads an ELF
 * file specified as a command-line argument, extracts the ELF header
 * information, and prints relevant details about the ELF file.
 * If any error occurs during file operations or ELF header processing,
 * appropriate error messages are printed to the standard error stream
 * and the program exits with exit code 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int file_descriptor, read_result;

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(98);
	}

	read_result = read(file_descriptor, header, sizeof(Elf64_Ehdr));
	if (read_result == -1)
	{
		free(header);
		close_elf(file_descriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(file_descriptor);
	return (0);
}
