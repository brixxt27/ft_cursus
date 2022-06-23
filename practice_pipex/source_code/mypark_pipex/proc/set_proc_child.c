/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_proc_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:36:10 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:32:46 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"

void	set_proc_child(int heredoc, void (**proc_child)(t_proc_info *))
{
	proc_child[0] = proc_read_file;
	proc_child[1] = proc_write_file;
	proc_child[2] = proc_exe_cmd;
	if (heredoc)
	{
		proc_child[0] = proc_heredoc;
		proc_child[1] = proc_append_file;
	}
}
