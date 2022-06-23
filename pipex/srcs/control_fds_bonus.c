/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_fds_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:59:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/23 20:51:36 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../include/pipex.h"
#include <unistd.h>

void	open_infile_or_outfile(t_list *p_list, t_files *p_files)
{
	if (p_list->curr_idx == 2)
		open_safely(p_files, O_RDONLY);
	else
		open_safely(p_files, O_TRUNC | O_WRONLY | O_CREAT);
}

void	open_safely(t_files *p_files, int flag)
{
	if (flag == O_RDONLY)
	{
		p_files->input_fd = open(p_files->infile_name, flag);
		check_error(E_SYSTEM_CALL, (long long)p_files->input_fd);
	}
	else
	{
		p_files->output_fd = open(p_files->outfile_name, flag, 0666);
		check_error(E_SYSTEM_CALL, (long long)p_files->output_fd);
	}
}

void	close_safely(int fd)
{
	int	ret;

	ret = close(fd);
	check_error(E_SYSTEM_CALL, ret);
}

void	create_pipe(t_list *p_list)
{
	int		ret_pipe;

	ret_pipe = pipe(p_list->pipefd);
	check_error(E_SYSTEM_CALL, (long long)ret_pipe);
}

void	duplicate2_safely(int from, int to)
{
	int	ret;

	ret = dup2(from, to);
	check_error(E_SYSTEM_CALL, (long long)ret);
}
