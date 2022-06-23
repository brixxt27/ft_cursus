#include <unistd.h>
#include <stdio.h>

int		print_error(const char *str);

int	main(void)
{
	pid_t 	pid;
	int		argc = 2;
	char	*argv[] = {"ls", "-a", "-l", NULL};
	char	*envp[] = {NULL};

	if (argc < 2)
		return (print_error("argc"));
	
	execve("/bin/ls", argv, envp);
	return (0);
}

int		print_error(const char *str)
{
	perror(str);
	return (1);
}
