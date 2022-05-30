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
		printf("Error of file open in fd2");
		exit(1);
	}
	printf("%d\n", fd2);
	while (str1 || str2)
	{
		printf("%s", str1 = get_next_line(fd1));
		printf("%s", str2 = get_next_line(fd2));
	}
	//printf("%s\n", get_next_line(0));
	close(fd1);
	close(fd2);
	return (0);
}