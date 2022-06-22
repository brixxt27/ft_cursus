/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:58:48 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/22 21:59:08 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	make_pipex(t_list *p_list, t_files *p_files, int argc, char **argv)
{ 
	while (p_list->curr_idx < argc - 1)
	{
		parse_execve_argv(p_list, argv);
		if (p_list->curr_idx != argc - 2)
			create_pipe(p_list);
		p_list->pid = fork_safely();
		if (p_list->pid == CHILD)
			do_it_child(p_list, p_files, argc);
		do_it_parent(p_list, p_files, argc);
		++(p_list->curr_idx);
	}
}
