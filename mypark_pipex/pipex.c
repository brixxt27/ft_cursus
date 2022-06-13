/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:45:41 by mypark            #+#    #+#             */
/*   Updated: 2022/03/05 00:43:16 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include "include/proc.h"
#include "include/pipe.h"
#include "include/error.h"
#include "include/utils.h"

pid_t	fork_proc(t_proc_info *info)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < info->max_fork)
	{
		pid = fork();
		err_catch_fork(pid, i);
		if (pid == 0)
			break ;
		i++;
	}
	info->ch_num = i;
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t		pid;
	int			heredoc;
	void		(*proc_child[3])(t_proc_info *);
	t_proc_info	info;

	if (argc < 5)
		return (1);
	info.envp = envp;
	heredoc = is_same("heredoc", argv[1]);
	info.max_fork = argc - 1 - heredoc;
	set_proc_child(heredoc, proc_child);
	alloc_pipes(&info);
	pid = fork_proc(&info);
	if (pid != 0)
		proc_parent(&info);
	else
	{
		info.cmd = argv[info.ch_num + 1 + heredoc];
		if (info.ch_num == 0)
			proc_child[0](&info);
		else if (info.ch_num == info.max_fork - 1)
			proc_child[1](&info);
		else
			proc_child[2](&info);
	}
}
