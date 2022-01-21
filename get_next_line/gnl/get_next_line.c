#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char *get_next_line(int fd)
{
    char	*buf;
    int		size;

    buf = (char *)malloc(BUFFER_SIZE);
    if (!buf)
        return (NULL);
    size = read(fd, buf, BUFFER_SIZE);
    if (size == 0)
        return NULL; 
	return buf;
}