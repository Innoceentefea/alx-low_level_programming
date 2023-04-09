#include "main.h"

/**
 * create_file - creates a file and adds permission to it
 * @filename: The name of the file to be created
 * @text_content: content to be placed in the created file
 *
 * Return: 1 if successfull and -1 on err.
 */
int create_file(const char *filename, char *text_content)
{
	int fd = 0, ret = 0, i = 0;

	if (!filename)
		return (-1);

	if (!text_content)
		text_content = "";

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00600);
	if (fd < 0)
		return (-1);

	while (text_content[i])
		i++;

	ret = write(fd, text_content, i);
	if (ret < 0)
		return (-1);

	close(fd);

	return (1);
}
