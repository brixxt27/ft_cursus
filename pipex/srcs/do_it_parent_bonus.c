/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_parent_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:55:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/23 20:59:07 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <unistd.h>

void	close_file(t_files *p_files)
{
	int	ret;

	ret = close(p_files->input_fd);
	check_error(E_SYSTEM_CALL, (long long)ret);
}

void	do_it_parent(t_list *p_list, t_files *p_files, int argc)
{
	if (p_list->curr_idx != 2)
		close_safely(p_files->input_fd);
	if (p_list->curr_idx != argc - 2)
		close_safely(p_list->pipefd[1]);
	p_files->input_fd = p_list->pipefd[0];
}
