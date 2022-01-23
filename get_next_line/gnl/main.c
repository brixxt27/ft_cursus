#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"


int main()
{
    int fd;
    char *temp;

    fd = open("./text.txt", O_RDONLY);
    
    while ((temp = get_next_line(fd)))
    {
        printf("%s", temp);
    }
	free(temp);
	return (0);
}

