#include "libft.h"

int	main(int argc, char *argv[])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve();
	else
		printf("I'm parent!\n");
	return (0);
}
