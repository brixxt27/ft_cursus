#include "get_next_line.h"

char *get_next_line(int fd)
{
    char	*ret;
    int		size;

    ret = (char *)malloc(BUFFER_SIZE);
    if (!ret)
        return (NULL);
    size = read(fd, ret, BUFFER_SIZE);
    if (size == 0)
        return NULL; 
	return (ret);
}
