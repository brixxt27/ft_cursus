/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:55:08 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/19 15:55:41 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	close_file(t_files *p_files)
{
	int	ret;
	
	ret = close(p_files->input_fd);
	check_error(E_SYSTEM_CALL, (long long)ret);
}

void	do_it_parent(t_list *p_list, t_files *p_files, int count_argc)
{
	if (count_argc != LAST_CHILD)
		close_safely(p_list->pipefd[1]);
	p_files->input_fd = p_list->pipefd[0];
}
