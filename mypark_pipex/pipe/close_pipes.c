/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:35:28 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:29:40 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"
#include "safe.h"
#include <unistd.h>

void	close_pipes(t_proc_info *info)
{
	int	pi;

	pi = 1;
	while (pi < info->max_fork - 1)
	{
		safe_close(info->pipes[pi][0]);
		safe_close(info->pipes[pi][1]);
		pi++;
	}
	safe_close(info->pipes[0][1]);
	safe_close(info->pipes[info->max_fork - 1][0]);
}
