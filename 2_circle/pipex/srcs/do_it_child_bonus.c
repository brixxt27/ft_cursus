/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_child_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:51:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/23 20:59:07 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <unistd.h>

static void	execute_process(t_list *p_list)
{
	int		flag;
	size_t	i;
	char	*path;
	int		ret_execve;

	flag = 0;
	if (ft_strchr(p_list->execve_argv[0], '/'))
		flag = 1;
	i = 0;
	while (p_list->path[i])
	{
		if (flag == 1)
			path = p_list->execve_argv[0];
		else
			path = ft_add_slash_strjoin(p_list->path[i], \
									p_list->execve_argv[0]);
		check_error(E_MALLOC, (long long)path);
		ret_execve = execve(path, p_list->execve_argv, p_list->envp);
		ft_free_malloc(path);
		i++;
	}
	check_error(E_NO_PATH, (long long)ret_execve);
}

void	do_it_child(t_list *p_list, t_files *p_files, int argc)
{
	if (p_list->curr_idx == 2 || p_list->curr_idx == argc - 2)
		open_infile_or_outfile(p_list, p_files);
	duplicate2_safely(p_files->input_fd, 0);
	close_safely(p_files->input_fd);
	if (p_list->curr_idx != argc - 2)
	{
		close_safely(p_list->pipefd[0]);
		duplicate2_safely(p_list->pipefd[1], 1);
		close_safely(p_list->pipefd[1]);
	}
	else
	{
		duplicate2_safely(p_files->output_fd, 1);
		close_safely(p_files->output_fd);
	}
	execute_process(p_list);
}
