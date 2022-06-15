/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:20 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/15 17:04:25 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	check_error(t_error e, long long ret)
{
	if (e == E_MALLOC && !ret)
	{
		ft_putstr_fd("Memory allocation fails.\n", 2);
		exit(1);
	}
	if (e != E_MALLOC && ret == -1)
	{
		perror(NULL);
		exit(1);
	}
}

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	check_fork_error(pid_t pid)
{
	if (pid >= 0)
		return ;
	perror(NULL);
	exit(1);
}
