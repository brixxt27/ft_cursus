/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:59:41 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/16 21:01:46 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "pipex.h"
#include <unistd.h>

void	open_infile_and_outfile(t_files *p_list)
{
	p_list->infile_fd = open(p_list->infile_name, O_RDONLY);
	check_error(E_SYSTEM_CALL, (long long)p_list->infile_fd);
}

void	duplicate2_fd(t_files *p_list)
{
	int	fd;

	fd = dup2(p_list->infile_fd, 0);
	check_error(E_SYSTEM_CALL, (long long)fd);
}

void	close_file(t_files *p_list)
{
	close(p_list->infile_fd);
	check_error(E_SYSTEM_CALL, (long long)p_list->infile_fd);
}
