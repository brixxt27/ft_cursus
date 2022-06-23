/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:18:42 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 17:28:02 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"
#include "pipe.h"
#include "utils.h"
#include "safe.h"
#include <fcntl.h>
#include <unistd.h>

void	proc_heredoc(t_proc_info *info)
{
	char	*limiter;
	char	buf[BUFFER_SIZE + 1];
	int		read_size;
	int		to;

	limiter = ft_strjoin(info->cmd, "\n");
	to = info->pipes[info->ch_num][1];
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		read_size = safe_read(0, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		if (is_same(buf, limiter))
			break ;
		safe_write(to, buf, read_size);
	}
	close_pipes(info);
	free_pipes(info);
}
