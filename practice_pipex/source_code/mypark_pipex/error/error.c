/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:52:54 by mypark            #+#    #+#             */
/*   Updated: 2022/03/04 11:29:21 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "error.h"
#include "proc.h"
#include "utils.h"

void	err_catch(enum e_error e, int ret)
{
	if (e == err_alloc && ret == 0)
	{
		ft_putstr_fd("Memory allocation fails.\n", 2);
		exit(1);
	}
	if (e != err_alloc && ret == -1)
	{
		perror(NULL);
		exit(1);
	}
}

void	err_catch_fork(int ret, int ch_num)
{
	if (ret != -1)
		return ;
	wait_child(ch_num);
	perror(NULL);
	exit(1);
}
