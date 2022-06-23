/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:46:43 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:30:37 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proc.h"
#include "pipe.h"
#include "utils.h"

void	proc_parent(t_proc_info *info)
{
	close_pipes(info);
	free_pipes(info);
	wait_child(info->max_fork);
}
