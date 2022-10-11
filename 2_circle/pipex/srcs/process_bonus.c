/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:58:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/23 20:59:07 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <sys/wait.h>
#include <unistd.h>

pid_t	fork_safely(void)
{
	pid_t	pid;

	pid = fork();
	check_fork_error(pid);
	return (pid);
}

int	wait_all_child_and_return_status(t_list *p_list)
{
	int	status;
	int	cnt;
	int	ret_wait;
	int	ret;

	cnt = FIRST_CMD;
	while (cnt != p_list->curr_idx)
	{
		ret_wait = wait(&status);
		if (ret_wait != -1)
			cnt++;
		if (ret_wait == p_list->pid)
			ret = status;
	}
	return (ret);
}
