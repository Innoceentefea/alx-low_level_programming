#include "main.h"
#include <stdio.h>

/**
 * error - checks if files can be opened.
 * @file1: file_from.
 * @file2: file_to.
 * @args: arguments vector.
 * Return: no return.
 */
void error(int file1, int file2, char *args[])
{
	if (file1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", args[1]);
		exit(98);
	}
	if (file2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", args[2]);
		exit(99);
	}
}

/**
 * open_file - opens a file and checks for errors.
 * @filename: the name of the file to open.
 * @flags: the flags to use when opening the file.
 * @args: arguments vector.
 * Return: the file descriptor of the opened file.
 */
int open_file(char *filename, int flags, char *args[])

{
	int fd = open(filename, flags);

	error(fd, -1, args);

	return (fd);
}

/**
 * read_write - reads from one file descriptor and writes to another.
 * @from: the file descriptor to read from.
 * @to: the file descriptor to write to.
 * @args: arguments vector.
 * Return: no return.
 */
void read_write(int from, int to, char *args[])

{
	size_t nchars, nwr;
	char buf[1024];

	nchars = 1024;

	while (nchars == 1024)
	{
		nchars = read(from, buf, 1024);
		if (nchars == -1)
			error(-1, 0, args);
		nwr = write(to, buf, nchars);
		if (nwr == -1)
			error(0, -1, args);
	}
}

/**
 * close_file - closes a file descriptor and checks for errors.
 * @fd: the file descriptor to close.
 * @args: arguments vector.
 * Return: no return.
 */
void close_file(int fd, char *args[])

{

	int err_close = close(fd);

	if (err_close == -1)

	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - program that copies the content of a file to another file.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])

{
	int file1, file2;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file1 = open_file(argv[1], O_RDONLY, argv);
	file2 = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, argv);
	read_write(file1, file2, argv);
	close_file(file1, argv);
	close_file(file2, argv);

	return (0);
}
