/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:58:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/23 13:46:31 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <sys/wait.h>
#include <unistd.h>

pid_t	fork_safely(void)
{
	pid_t	pid;

	pid = fork();
	check_fork_error(pid);
	return (pid);
}

int	wait_all_child(t_list *p_list, int argc)
{
	int 	status;
	int		cnt;
	int		ret_wait;
	int		ret;

	cnt = 0;
	while (1)
	{
		ret_wait = wait(&status);
		if (ret_wait != -1)
			cnt++;
		if (ret_wait == p_list->pid)
			ret = status;
		if (cnt == argc - 3)
			break ;
	}
	return (ret);
}
