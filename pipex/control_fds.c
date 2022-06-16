/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:59:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/17 00:55:38 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "pipex.h"
#include <unistd.h>

void	open_infile_and_outfile(t_files *p_files)
{
	p_files->infile_fd = open(p_files->infile_name, O_RDONLY);
	check_error(E_SYSTEM_CALL, (long long)p_files->infile_fd);
	p_files->outfile_fd = open(p_files->outfile_name, O_WRONLY);
	check_error(E_SYSTEM_CALL, (long long)p_files->outfile_fd);
}

void	create_pipe(t_list *p_list)
{
	int		ret_pipe;

	ret_pipe = pipe(p_list->pipefd);
	check_error(E_SYSTEM_CALL, (long long)ret_pipe);
}
