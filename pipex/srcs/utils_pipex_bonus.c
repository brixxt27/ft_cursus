/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:13:38 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/23 20:51:43 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_utils(t_list *p_list, char **envp)
{
	p_list->curr_idx = 2;
	p_list->envp = envp;
}

void	free_string_array(char ***p_ret)
{
	char	**ret;

	ret = *p_ret;
	while (*ret)
	{
		free(*ret);
		*ret = NULL;
		ret++;
	}
	free(*p_ret);
	*p_ret = NULL;
}

void	free_all(t_list *p_list)
{
	free_string_array(&p_list->execve_argv);
}
