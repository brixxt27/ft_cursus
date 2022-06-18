/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:59:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/18 22:01:46 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "pipex.h"
#include <unistd.h>

void	open_infile_and_outfile(t_files *p_files)
{
	p_files->input_fd = open(p_files->infile_name, O_RDONLY);
	check_error(E_SYSTEM_CALL, (long long)p_files->input_fd);
	p_files->outfile_fd = open(p_files->outfile_name, O_WRONLY);
	check_error(E_SYSTEM_CALL, (long long)p_files->outfile_fd);
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

void	dup2_safely(int from, int to)
{
	int	ret;

	ret = dup2(from, to);
	check_error(E_SYSTEM_CALL, (long long)ret);
}
