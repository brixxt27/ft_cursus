/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:51:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/19 20:40:25 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

static void	execute_process(t_list *p_list)
{
	size_t	i;
	char	*path;
	int		ret_execve;

	i = 0;
	while (p_list->dir_path[i])
	{
		if (i == 0)
			path = ft_add_slash_strjoin(p_list->dir_path[i] + 5, \
									p_list->execve_argv[0]);
		else
			path = ft_add_slash_strjoin(p_list->dir_path[i], \
									p_list->execve_argv[0]);
		check_error(E_MALLOC, (long long)path);
		ret_execve = execve(path, p_list->execve_argv, p_list->envp);
		ft_free_malloc(path);
		i++;
	}
	check_error(E_NO_PATH, (long long)ret_execve);
}

// Consider when process call last child process.
void	do_it_child(t_list *p_list, t_files *p_files, int count_argc)
{
	if (count_argc != LAST_CHILD)
		close_safely(p_list->pipefd[0]);
	duplicate2_safely(p_files->input_fd, 0);
	close_safely(p_files->input_fd);
	if (count_argc != LAST_CHILD)
	{
		duplicate2_safely(p_list->pipefd[1], 1);
		close_safely(p_list->pipefd[1]);
	}
	else
		duplicate2_safely(p_files->output_fd, 1);
	execute_process(p_list);
}
