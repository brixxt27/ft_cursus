#include "microshell.h"
#include <unistd.h>
#include <string.h>
//err
#include <stdio.h>

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

int	init_execve_info(char** argv, t_execve_info* execve_info, int i)
{
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
			i++;
			break;
		}
		i++;
	}
	return i;
}

void	do_it_child(t_execve_info* execve_info, t_pipe* pipe_info)
{
	if (pipe_info->pipe_fd[0] != 0)
		close(pipe_info->pipe_fd[0]);
	dup2(pipe_info->pipe_fd[1], 1);
	execve(execve_info->path, execve_info->argv, execve_info->envp);
	ft_putstr_err("error: fatal\n");
}

int	main(int argc, char* argv[], char* envp[])
{
	t_execve_info	execve_info = {
									NULL,
									NULL,
									envp,
									e_null
	};
	int		i = 1;
	int		ret;
	pid_t	pid;
	t_pipe	pipe_info = {{0, 1}, 0};

	if (argc < 2)
		return 0;
	
	while (argc > i) {
		i = init_execve_info(argv, &execve_info, i);
		
		// test
		//printf("type: %d\n", execve_info.type);
		if (execve_info.type == e_pipe) {
			ret = pipe(pipe_info.pipe_fd);
			if (ret == -1) {
				ft_putstr_err("error: fatal\n");
				return 1;
			}
		}

		pid = fork();
		if (pid == -1)
			return ft_putstr_err("error: fatal\n");
		if (pid == 0) {
			do_it_child(&execve_info, &pipe_info);
			return 1;
		}
		//do_it_parent();

		i++;
	}
}
