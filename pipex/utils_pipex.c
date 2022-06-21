/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:13:38 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/21 20:45:42 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_num_command(int argc)
{
	return (argc - 3);
}

void	init_utils(t_list *p_list, char **envp)
{
	p_list->envp = envp;
}
