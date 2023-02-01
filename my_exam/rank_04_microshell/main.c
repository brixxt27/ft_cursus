#include "myshell.h"

#include <fcntl.h>

/**
 * utils
 */

static int	ft_strlen(char* str)
{
	int len = 0;

	while (*str)
	{
		str++;
		len++;
	}
	return len;
}

static void	ft_putstr_err(char* str)
{
	write(STDERR, str, ft_strlen(str));
}

static void	system_call_err()
{
	ft_putstr_err("error: fatal\n");
	exit(1);
}

void	safe_dup2_and_close(int old, int new)
{
	int ret;

	//printf("old: %d, new: %d\n", old, new);
	//printf("fd: %d, is available: %d\n", old, fcntl(old, F_GETFD));
	//printf("fd: %d, is available: %d\n", new, fcntl(new, F_GETFD));
	ret = dup2(old, new);
	if (ret == -1)
		system_call_err();
	close(old);
}

/**
 * main logics
 */

int	init_execve_info(char** argv, t_execve_info* execve_info, int i)
{
	execve_info->path = argv[i];
	execve_info->argv = &argv[i];
	execve_info->prev_type = execve_info->curr_type;
	while (1) {
		if (argv[i + 1] == NULL \
			|| strncmp(argv[i + 1], "|", 2) == 0 \
			|| strncmp(argv[i + 1], ";", 2) == 0)
		{
			if (argv[i + 1] == NULL)
				execve_info->curr_type = e_null;
			else if (strncmp(argv[i + 1], "|", 2) == 0)
				execve_info->curr_type = e_pipe;
			else
				execve_info->curr_type = e_semicolon;
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
	if (execve_info->curr_type == e_pipe)
	{
		close(pipe_info->curr_pipe[0]);
		safe_dup2_and_close(pipe_info->curr_pipe[1], 1);
	}
	if (execve_info->prev_type == e_pipe)
	{
		safe_dup2_and_close(pipe_info->prev_read_pipe, 0);
	}
	execve(execve_info->path, execve_info->argv, execve_info->envp);
	ft_putstr_err("error: cannot execute ");
	ft_putstr_err(execve_info->path);
	ft_putstr_err("\n");
	exit(1);
}

void	do_it_parent(t_execve_info* execve_info, t_pipe* pipe_info)
{
	if (pipe_info->prev_read_pipe != -1)
		close(pipe_info->prev_read_pipe);
	if (execve_info->curr_type == e_pipe)
	{
		close(pipe_info->curr_pipe[1]);
		pipe_info->prev_read_pipe = pipe_info->curr_pipe[0];
	}
	else if (execve_info->prev_type == e_pipe)
	{
		close(pipe_info->prev_read_pipe);
	}
}

void	wait_all_process(int cnt_process)
{
	int ret;

	for (int i = 0; i < cnt_process; i++)
	{
		ret = waitpid(-1, NULL, 0);
		if (ret == -1)
			system_call_err();
	}
}

void	ft_cd(t_execve_info* execve_info)
{
	int	i = 0;
	int	ret;
	//char*	e_argv[2] = {"bin/pwd", NULL};

	while (1)
	{
		if (execve_info->argv[i + 1] == NULL)
			break;
		i++;
	}
	if (i != 1)
	{
		ft_putstr_err("error: cd: bad arguments\n");
		return;
	}
	ret = chdir(execve_info->argv[1]);
	if (ret == -1)
	{
		ft_putstr_err("error: cd: cannot change directory to ");
		ft_putstr_err(execve_info->argv[1]);
		ft_putstr_err("\n");
		return;
	}
	//execve("/bin/pwd", e_argv, execve_info->envp);
}

int	main(int argc, char* argv[], char* envp[])
{
	t_execve_info	execve_info =
	{
		NULL,
		NULL,
		envp,
		e_null,
		e_null
	};
	int		i = 1;
	int		ret;
	pid_t	pid;
	t_pipe	pipe_info = {{0, 1}, 0};
	int		cnt_process = 0;

	if (argc < 2)
		return 0;
	
	while (argc > i)
	{
		i = init_execve_info(argv, &execve_info, i);
		
		if (strncmp(execve_info.path, "cd", 3) != 0 \
			&& execve_info.curr_type == e_pipe)
		{
			ret = pipe(pipe_info.curr_pipe);
			if (ret == -1)
				system_call_err();
		}
		else if (execve_info.prev_type == e_semicolon)
		{
			wait_all_process(cnt_process);
			cnt_process = 0;
		}

		if (strncmp(execve_info.path, "cd", 3) == 0)
		{
			ft_cd(&execve_info);
			i++;
			continue;
		}

		pid = fork();
		if (pid == -1)
			system_call_err();
		if (pid == 0)
			do_it_child(&execve_info, &pipe_info);
		//printf("fd: %d, is available: %d\n", pipe_info.prev_read_pipe, fcntl(pipe_info.prev_read_pipe, F_GETFD));
		do_it_parent(&execve_info, &pipe_info);

		cnt_process++;
		i++;
	}
	close(pipe_info.prev_read_pipe);
	wait_all_process(cnt_process);
	while (1);
}
