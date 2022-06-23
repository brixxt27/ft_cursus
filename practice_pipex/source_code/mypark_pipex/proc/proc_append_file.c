/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_append_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:17:46 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 18:51:12 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"
#include "safe.h"
#include "pipe.h"
#include "safe.h"
#include <unistd.h>
#include "test.h"

void	proc_append_file(t_proc_info *info)
{
	char	*file_name;
	int		outfd;
	int		read_size;
	char	buf[BUFFER_SIZE];

	file_name = info->cmd;
	outfd = safe_open(file_name, O_APPEND | O_WRONLY);
	safe_dup2(info->pipes[info->ch_num][0], 0);
	close_pipes(info);
	free_pipes(info);
	read_size = safe_read(0, buf, BUFFER_SIZE);
	while (read_size != 0)
	{
		safe_write(outfd, buf, read_size);
		read_size = safe_read(0, buf, BUFFER_SIZE);
	}
	safe_close(outfd);
	safe_close(0);
}
