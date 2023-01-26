#include "get_next_line.h"

static int	init_gnl(char *str)
{

}

static int	read_file(fd, str)
{
	ssize_t	ret;

	ret = read(fd, str, 1);
	if (ret < 0)
		return (0);
	
}

char	*get_next_line(int fd)
{
	char	*str;

	if (fd < 0 | BUFFER_SIZE <= 0)
		return (NULL);
	if (init_gnl(str) == 0)
		return (NULL);
	if (read_file(fd, str) == 0)
		return (NULL);
}
