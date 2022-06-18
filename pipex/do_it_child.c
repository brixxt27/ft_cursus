/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:51:32 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/18 22:01:46 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

static void	execute_process(t_list *p_list)
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
		check_error(E_MALLOC, (long long)path);
		execve(path, p_list->execve_argv, p_list->envp);
		ft_free_malloc(path);
		i++;
	}
	print_error("Execve can't execute!\n");
}

void	do_it_child(t_list *p_list, t_files *p_files)
{
	close_safely(p_list->pipefd[0]);
	duplicate2_fd(p_files->input_fd, 0);
	execute_process(p_list);
}
