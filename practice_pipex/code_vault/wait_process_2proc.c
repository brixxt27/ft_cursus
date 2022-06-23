#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		status;
	int		n;

	pid = fork();
	status = 0;
	if (pid == 0)
		n = 1;
	else
		n = 6;
	printf("\n%d\n", pid);
	if (pid != 0)
	{
		wait(&pid);
		printf("\nParent is here! %d\n", pid);
	}
	for (int i = n; i < n + 5; i++)
	{
		printf("%d ", i);
	}	
	if (pid != 0)
		printf("%d\n", pid);
	return (0);
}