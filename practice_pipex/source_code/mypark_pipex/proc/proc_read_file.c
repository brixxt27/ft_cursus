/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_read_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:51:19 by mypark            #+#    #+#             */
/*   Updated: 2022/03/05 01:45:41 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"
#include "pipe.h"
#include "safe.h"
#include <fcntl.h>
#include <unistd.h>
#include "test.h"

void	proc_read_file(t_proc_info *info)
{
	char	*file_name;
	int		infd;
	char	buf[BUFFER_SIZE];
	int		read_size;

	file_name = info->cmd;
	infd = safe_open(file_name, O_RDONLY);
	safe_dup2(info->pipes[info->ch_num][1], 1);
	close_pipes(info);
	free_pipes(info);
	read_size = safe_read(infd, buf, BUFFER_SIZE);
	while (read_size != 0)
	{
		safe_write(1, buf, read_size);
		read_size = safe_read(infd, buf, BUFFER_SIZE);
	}
	safe_close(infd);
	safe_close(1);
}
