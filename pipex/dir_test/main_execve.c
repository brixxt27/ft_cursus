#include <unistd.h>
#include <stdio.h>

int		print_err(const char *str);

int	main(void)
{
	pid_t 	pid;
	int		argc = 2;
	char	*argv[] = {"ls", "-a", "-l", NULL};
	char	*envp[] = {NULL};

	if (argc < 2)
		return (print_err("argc"));
	
	execve("/bin/ls", argv, envp);
	return (0);
}

int		print_err(const char *str)
{
	perror(str);
	return (1);
}