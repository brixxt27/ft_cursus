/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:20 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/14 20:45:49 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	check_error(t_error e, void *mem)
{
	if (e == E_MALLOC && !mem)
	{
		ft_putstr_fd("Memory allocation fails.\n", 2);
		exit(1);
	}
	if (e == E_SYSTEM)
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
