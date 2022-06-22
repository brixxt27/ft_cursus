/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:27:20 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/19 22:08:38 by jayoon           ###   ########.fr       */
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
	else if (e == E_NO_PATH)
	{
		perror(NULL);
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

// fork 함수를 부모 프로세스에서 실패한다면 이전에 만든 자식 프로세스를 종료될 때까지 기다리고, 전부 wait 으로 수거해줘야 한다.
void	check_fork_error(pid_t pid)
{
	if (pid >= 0)
		return ;
	perror(NULL);
	exit(1);
}
