/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:20 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/23 20:59:07 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

void	check_error(t_error e, long long ret)
{
	if (e == E_MALLOC && !ret)
	{
		ft_putstr_fd("Memory allocation fails.\n", 2);
		exit(1);
	}
	else if (e == E_NO_PATH)
	{
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	else if (e != E_MALLOC && ret == -1)
	{
		perror(NULL);
		exit(1);
	}
}

void	check_libft_error(char *error_str, char *mem)
{
	if (!mem)
	{
		ft_putstr_fd(error_str, 2);
		exit(1);
	}
}

void	print_error(char *error_str)
{
	ft_putstr_fd(error_str, 2);
	exit(1);
}

void	check_fork_error(pid_t pid)
{
	if (pid >= 0)
		return ;
	perror(NULL);
	exit(1);
}
