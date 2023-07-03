#include "myshell.h"

/**
 * utils
 */

static int	ft_strlen(const char* str)
{
	int len = 0;

	while (*str)
	{
		str++;
		len++;
	}
	return len;
}

static void	ft_putstr_err(const char* str)
{
	write(2, str, ft_strlen(str));
}

static void	system_call_err()
{
	ft_putstr_err("error: fatal\n");
	exit(1);
}

void	safe_dup2_and_close(int old, int new)
{
	int ret;

	ret = dup2(old, new);
	if (ret == -1)
		system_call_err();
	close(old);
}

/**
 * main logics
 */

int	init_cmd_info(char** argv, t_command_info* execve_info, int i)
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
				execve_info->curr_type = kNull;
			else if (strncmp(argv[i + 1], "|", 2) == 0)
				execve_info->curr_type = kPipe;
			else
				execve_info->curr_type = kSemicolon;
			argv[i + 1] = NULL;
			i++;
			break;
		}
		i++;
	}
	return i;
}

void	do_it_child(t_command_info* execve_info, t_pipe* pipe_info)
{
	if (execve_info->curr_type == kPipe)
	{
		close(pipe_info->curr_pipe[0]);
		safe_dup2_and_close(pipe_info->curr_pipe[1], 1);
	}
	if (execve_info->prev_type == kPipe)
	{
		safe_dup2_and_close(pipe_info->prev_read_pipe, 0);
	}
	execve(execve_info->path, execve_info->argv, execve_info->envp);
	ft_putstr_err("error: cannot execute ");
	ft_putstr_err(execve_info->path);
	ft_putstr_err("\n");
	exit(1);
}

void	do_it_parent(t_command_info* execve_info, t_pipe* pipe_info)
{
	if (execve_info->prev_type == kPipe)
	{
		close(pipe_info->prev_read_pipe);
	}
	if (execve_info->curr_type == kPipe)
	{
		close(pipe_info->curr_pipe[1]);
		pipe_info->prev_read_pipe = pipe_info->curr_pipe[0];
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

void	ft_cd(t_command_info* execve_info)
{
	int	i = 0;
	int	ret;

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
	}
}

int	main(int argc, char* argv[], char* envp[])
{
	t_command_info	execve_info =
	{
		NULL,
		NULL,
		envp,
		kNull,
		kNull
	};
	int		i = 1; // argv[0] 은 프로그램 명
	int		ret;
	pid_t	pid;
	t_pipe	pipe_info = {{0, 1}, 0};
	int		cnt_process = 0;

	if (argc < 2)
		return 0;
	
	while (argc > i)
	{
		if (strncmp(argv[i], ";", 2) == 0)
		{
			i++;
			continue;
		}

		i = init_cmd_info(argv, &execve_info, i);
		
		if (strncmp(execve_info.path, "cd", 3) != 0 \
			&& execve_info.curr_type == kPipe)
		{
			ret = pipe(pipe_info.curr_pipe);
			if (ret == -1)
				system_call_err();
		}

		if (execve_info.prev_type == kSemicolon)
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
		do_it_parent(&execve_info, &pipe_info);

		cnt_process++;
		i++;
	}
	wait_all_process(cnt_process);
}
