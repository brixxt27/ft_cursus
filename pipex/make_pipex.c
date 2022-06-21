/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:58:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/21 19:05:22 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_pipex(t_list *p_list, t_files *p_files, int argc, char **argv)
{ 
	while (p_list->num_command)
	{
		parse_execve_argv(p_list, argc, p_list->num_command, argv);
		if (p_list->num_command != LAST_CHILD)
			create_pipe(p_list);
		p_list->pid = fork_process();
		if (p_list->pid == CHILD)
			do_it_child(p_list, p_files, p_list->num_command);
		do_it_parent(p_list, p_files, p_list->num_command);
		--(p_list->num_command);
	}
}
