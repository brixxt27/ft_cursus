#include "microshell.h"
#include <stdio.h>
#include <string.h>

int	ft_strlen(char* str)
{
	int	len = 0;

	while (*str) {
		str++;
		len++;
	}
	return len;
}

void	ft_putstr_fd(char* str, int fd)
{
	for (int i = 0; i < ft_strlen(str); i++) {
		write(fd, &str[i], 1);
	}
}

void	ft_putstr_fd_three(char* s1, char* s2, char* s3, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putstr_fd(s2, fd);
	ft_putstr_fd(s3, fd);
}

void	ft_memcpy(char* dst, const char* src, size_t len)
{
	size_t	i = 0;

	while (i < len) {
		dst[i] = src[i];
		++i;
	}
}

static int	get_cnt_word(char* str)
{
	int	i = 0;
	int	cnt_word = 0;

	while (1) {
		if (str[i] == '\0')
			break;
		if (str[i] == ' ') {
			i++;
			continue;
		}
		if (str[i + 1] == ' ' || str[i + 1] == '\0')
			cnt_word++;
		i++;
	}
	return cnt_word;
}

static void	fill_str(char* str, char** ret)
{
	char*			begin;
	char*			end;
	enum e_isword	flag = e_noword;

	while (*str) {
		if (*str == ' ') {
			++str;
			continue;
		}
		if (flag == e_noword) {
			begin = str;
			flag = e_yesword;
		}
		if (*(str + 1) == ' ' || *(str + 1) == '\0') {
			end = str;
			*ret = malloc(sizeof(char) * (end - begin + 2));
			ft_memcpy(*ret, begin, sizeof(char) * (end - begin + 2));
			flag = e_noword;
			ret++;
		}
		++str;
	}
}

static char**	ft_split(char* str)
{
	int		cnt_word = 0;
	char**	ret;

	cnt_word = get_cnt_word(str);
	ret = malloc(sizeof(char*) * (cnt_word + 1));
	if (ret == NULL) {
		ft_putstr_fd("malloc error\n", FT_STDOUT);
		return NULL;
	}
	ret[cnt_word] = NULL;
	fill_str(str, ret);
	return ret;
}

static void	init_exceve_args(char* str, t_execve_info* execve_info)
{
	execve_info->argv = ft_split(str);
	execve_info->path = execve_info->argv[0];
}

static void	free_all(char** arr)
{
	int	i = 0;

	while (1) {
		if (arr[i] == NULL)
			break;
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	print_all(char** argv)
{
	while (*argv) {
		ft_putstr_fd(*argv, 1);
		ft_putstr_fd("\n", 1);
		argv++;
	}
}

static int	do_it_child(t_execve_info* execve_info)
{
	execve(execve_info->path, execve_info->argv, execve_info->envp);
	ft_putstr_fd_three("error: cannot execve ", execve_info->path, "\n", FT_STDERR);
	return -1;
}

//static int	control_pipe(pid_t pipe_fd)
//{

//}

int	main(int argc, char* argv[], char* envp[])
{
	t_execve_info	execve_info = 	{
										NULL,
										NULL,
										envp,
										0
									};
	int				i = 1;
	pid_t			pid;
	int				pipe_fd[2];
	int				ret;


	if (argc < 2) {
		return 1;
	}
	//check_valid_argv(argv);
	while (argv[i]) {
		init_exceve_args(argv[i], &execve_info);

		if (strncmp(argv[i + 1], "|", 1) == 0) {
			ret = pipe(pipe_fd);
			if (ret == -1) {
				ft_putstr_fd("error: fatal\n", FT_STDERR);
				return 1;
			}
		}

		pid = fork();
		if (pid == -1) {
			ft_putstr_fd("error: fatal\n", FT_STDERR);
			return 1;
		}
		if (pid == 0) {
			if (argv[i + 1] == "|")
				control_pipe(pipe_fd);
			if (do_it_child(&execve_info) == -1)
				return 1;
		}
		//do_it_parent();

		//print_all(execve_info.argv);
		free_all(execve_info.argv);
		i++;
	}
	// system("leaks microshell");
	return 0;
}
