#include <stdlib.h>	// exit
#include <stdio.h>	// printf
#include <fcntl.h>	// open
#include <unistd.h>	// close
#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*str1 = "start";
	char	*str2 = "start";

	if ((fd1 = open("text1", O_RDONLY)) < 0)
	{
		printf("Error of file open in fd1");
		exit(1);
	}
	if ((fd2 = open("text2", O_RDONLY)) < 0)
	{
		printf("Error of file open in fd1");
		exit(1);
	}
	// printf("%s", str1 = get_next_line(fd1));
	// free(str1);
	// str1 = NULL;
	// printf("%s", str2 = get_next_line(fd2));
	// free(str2);
	// str2 = NULL;
	while (str1 || str2)
	{
		printf("%s", str1 = get_next_line(fd1));
		if (str1)
			free(str1);
		printf("%s", str2 = get_next_line(fd2));
		if (str2)
			free(str2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
