/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:53:41 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:29:49 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"
#include <stdlib.h>

void	free_pipes(t_proc_info *info)
{
	int	pi;

	pi = 0;
	while (pi < info->max_fork)
	{
		free(info->pipes[pi]);
		pi++;
	}
	free(info->pipes);
}
