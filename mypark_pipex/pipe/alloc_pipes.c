/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:12:53 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:29:29 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"
#include "error.h"
#include "safe.h"

void	alloc_pipes(t_proc_info *info)
{
	int	pi;

	info->pipes = safe_malloc(sizeof(int *), info->max_fork);
	info->pipes[0] = safe_malloc(sizeof(int), 2);
	info->pipes[0][0] = 0;
	pi = 1;
	while (pi < info->max_fork)
	{
		info->pipes[pi] = safe_malloc(sizeof(int), 2);
		safe_pipe(info->pipes[pi]);
		info->pipes[pi - 1][1] = info->pipes[pi][1];
		pi++;
	}
	info->pipes[info->max_fork - 1][1] = 1;
}
