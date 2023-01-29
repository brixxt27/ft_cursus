#include "microshell.h"
#include <unistd.h>
#include <string.h>

int	ft_strlen(char* str)
{
	int len = 0;

	while (*str) {
		str++;
		len++;
	}
	return len;
}

int	ft_putstr_err(char* str)
{
	for (int i = 0; i < ft_strlen(str); i++) {
		write(1, &str[i], STDERR);
	}
	return 1;
}

int	init_execve_info(char** argv, t_execve_info* execve_info, int last_argv_idx)
{
	int i = last_argv_idx + 1;

	execve_info->path = argv[i];
	execve_info->argv = &argv[i];
	while (1) {
		if (argv[i + 1] == NULL || strncmp(argv[i + 1], "|", 1) == 0 || strncmp(argv[i + 1], ";", 1) == 0) {
			if (argv[i + 1] == NULL)
				execve_info->type = e_null;
			else if (strncmp(argv[i + 1], "|", 1) == 0)
				execve_info->type = e_pipe;
			else
				execve_info->type = e_semicolon;
			argv[i + 1] = NULL;
			break;
		}
		i++;
	}
	return i;
}

int	main(int argc, char* argv[], char* envp[])
{
	t_execve_info	execve_info = {
									NULL,
									NULL,
									envp,
									e_null
	};
	int		i = 0;
	int		last_argv_idx = 0;
	pid_t	pid;

	if (argc < 2)
		return 0;
	
	while (argv[i] != NULL) {
		last_argv_idx = init_execve_info(argv, &execve_info, last_argv_idx);
		pid = fork();
		if (pid == -1)
			return ft_putstr_err("error: fatal\n");
		if (pid == 0) {
			//do_it_child();
		}
		//do_it_parent();
		i++;
	}
}
