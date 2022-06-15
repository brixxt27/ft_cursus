
void	execute_process(t_list *p_list, char *envp[])
{
	size_t	i;
	char	*path;

	i = 0;
	while (p_list->dir_path[i])
	{
		if (i == 0)
			path = ft_add_slash_strjoin(p_list->dir_path[i] + 5, \
									p_list->execve_argv[0]);
		else
			path = ft_add_slash_strjoin(p_list->dir_path[i], \
									p_list->execve_argv[0]);
		check_error(E_MALLOC, path);
		execve(path, p_list->execve_argv, envp);
		ft_free_malloc(path);
		i++;
	}
	print_error("Execve can't execute!\n");
}

pid_t	fork_process(void)
{
	pid_t	pid;

	pid = fork();
	check_fork_error(pid);
	return (pid);
}
