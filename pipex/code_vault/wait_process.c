#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t	pid;
	pid_t	ppid;
	int		n;
	int		status;

	status = 0;
	n = 1;
	pid = fork();
	if (pid < 0)
	{
		perror("process create");
		return (-1);
	}
	while (n < 9 && pid != 0)
	{
		if (pid != 0)
		{
			n++;
			pid = fork();
		}
	}
	while ((ppid = wait(&status)) > 0);
	if (pid != 0)
		n++;
	printf("my pid is %d, n is %d\n", pid, n);
	return (0);
	/*
		프로세스를 10 개를 만들 것인데 프로세스 마다 1부터 출력해서 1씩 더해진 값을 출력할 것이다.
	*/
}