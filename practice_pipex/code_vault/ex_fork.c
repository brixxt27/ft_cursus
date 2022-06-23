#include "libft.h"

int	main(int argc, char *argv[])
{
	pid_t	pid;

	pid = fork();
	if (pid != 0)
		fork();
	printf("Hello pipex!\n");
	return (0);
}
