#include "microshell.h"

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

int	get_path_size(char* str)
{
	int	i = 0;

	while (1) {
		if (str[i] == ' ' || str[i] == '\0')
			break;
		i++;
	}
	return i;
}

static void	init_path(char* str, t_execve_info* execve_info)
{
	//int	i = 0;

	execve_info->path_size = get_path_size(str);
	execve_info->path = malloc(sizeof(char) * (execve_info->path_size + 1));
	if (execve_info->path == NULL) {
		ft_putstr_fd("malloc error\n", FT_STDOUT);
		return;
	}
}

static int	get_cnt_word(char* str, t_execve_info* execve_info)
{
	int	i = execve_info->path_size - 1;

	
}

static void	init_argv(char* str, t_execve_info* execve_info)
{
	int	cnt_word = 1;

	if (execve_info->path_size != ft_strlen(str)) {
		cnt_word += get_cnt_word(str, execve_info);
	}
	execve_info->argv = malloc(sizeof(char*) * (cnt_word + 1));
	if (execve_info->argv == NULL) {
		ft_putstr_fd("malloc error\n", FT_STDOUT);
		return;
	}
}

static void	init_exceve_args(char* str, t_execve_info* execve_info)
{
	int	i = 0;

	init_path(str, execve_info);
	init_argv(str, execve_info);
}


int	main(int argc, char* argv[], char* envp[])
{
	t_execve_info	execve_info = 	{
										NULL,
										NULL,
										0
									};
	int				i = 1;

	if (argc < 2) {
		return 1;
	}
	//check_valid_argv(argv);
	while (argv[i]) {
		init_exceve_args(argv[i], &execve_info);

		i++;
	}
	//execve(path, arr, envp);
}
