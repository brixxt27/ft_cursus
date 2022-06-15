/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayoon <jayoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:01:38 by jayoon            #+#    #+#             */
/*   Updated: 2022/06/15 16:59:29 by jayoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_argv(t_list *p_list, char **argv, char **envp)
{
	p_list->infile_name = argv[1]; 
	p_list->dir_path = NULL;
	p_list->execve_argv = ft_split(argv[2], ' ');
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			p_list->dir_path = ft_split(*envp, ':');
			break ;
		}
		envp++;
	}
	if (p_list->dir_path == NULL)
		print_error("Not exist path!\n");
}
